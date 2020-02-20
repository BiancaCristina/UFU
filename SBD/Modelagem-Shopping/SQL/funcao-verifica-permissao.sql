/*
SET ROLE jose;
SET ROLE josefina;
SET ROLE NONE;
*/

/* Funcao que verifica se um usuario eh do normal_user ou admin_user */

-- Caso ele tenha alguma permissao de UPDATE em qualquer tabela, entao eh admin_user
-- Caso contrario, nao eh admin_user
CREATE OR REPLACE FUNCTION verifica_permissao ()
RETURNS boolean AS $$

DECLARE
	permissao boolean;
	
BEGIN
	SELECT has_table_privilege ('aluga', 'UPDATE') INTO permissao; 
	
	RETURN permissao; 
END $$ LANGUAGE 'plpgsql';


/* Funcao que realiza o login */
CREATE OR REPLACE FUNCTION fazer_login
(
	IN usuario text
) RETURNS boolean AS $$

DECLARE
	contador  integer;
	
BEGIN	
	-- Verifica se esse usuario esta no banco
	SELECT 
		COUNT (usename) INTO contador
	FROM pg_user
	WHERE usename = usuario;
	
	-- Retorna true se logar ou false se nao logar
	IF (contador > 0) THEN
		EXECUTE format('SET ROLE %I', usuario);
		RETURN true; 
	END IF;
	
	IF (contador = 0) THEN
		RETURN false;
	END IF;
	
END $$ LANGUAGE 'plpgsql';

/* TESTES */
-- SET ROLE NONE; 
--SELECT login('josefdfsdfsdina');
--SELECT CURRENT_USER;
-- SELECT verifica_permissao();
-- DROP FUNCTION login(varchar);
