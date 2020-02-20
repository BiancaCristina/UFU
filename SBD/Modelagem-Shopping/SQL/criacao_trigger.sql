/* Criacao do trigger que forca a autenticacao do usuario como admin_user para que faca insert, update ou delete */
CREATE OR REPLACE FUNCTION autentica_usuario ()
RETURNS TRIGGER AS $$

DECLARE
	permissao boolean;
	
BEGIN
	SELECT has_table_privilege ('aluga', 'UPDATE') INTO permissao; 
	
	IF (permissao = true) THEN
		RETURN NEW;
	END IF;
	
	IF (permissao = false) THEN
		RETURN NULL;
	END IF;
	
END $$ LANGUAGE 'plpgsql';

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON administrador
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON aluga
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON banco
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON cinema
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON cozinheiro
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON departamento_administrativo
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON emp_corporativo
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON empresa_corporativa
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON estacionamento
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON evento
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON funcionario
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON locatario
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON organizador
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON praca_alimentacao
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON restaurante
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON sala
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON tipo_comodo
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON trabalha_departamento_adm
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON trabalha_emp_corporativa
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();

CREATE TRIGGER trigger_autentica_usuario
BEFORE INSERT OR UPDATE OR DELETE ON trabalha_restaurante
FOR EACH ROW
EXECUTE PROCEDURE autentica_usuario();


/* Criação do trigger que impede que o funcionário possa ter mais de um sub-tipo de funcionário */
CREATE OR REPLACE FUNCTION limita_funcoes_func ()
RETURNS TRIGGER AS $$

DECLARE
contador integer;

BEGIN
	contador:= 0;
	
	SELECT COUNT(coz.cpf) INTO contador
	FROM cozinheiro AS coz
	WHERE coz.cpf = new.cpf;
		
	IF (contador > 0) THEN
		-- Nesse caso, ja eh cozinheiro, logo nao pode estar em outro tipo de funcionario
		RAISE EXCEPTION 'CPF ja cadastrado em algum sub-tipo de funcionario!';
		RETURN NULL;
	END IF;
	
	contador:=0;
	
	SELECT COUNT (corp.cpf) INTO contador
	FROM emp_corporativo AS corp
	WHERE corp.cpf = new.cpf;
	
	IF (contador > 0) THEN
		-- Nesse caso, ja eh empregado corporativo, logo nao pode estar em outro tipo de funcionario
		RAISE EXCEPTION 'CPF ja cadastrado em algum sub-tipo de funcionario!';
		RETURN NULL;
	END IF;
	
	SELECT COUNT(adm.cpf) INTO contador
	FROM administrador AS adm
	WHERE adm.cpf = new.cpf;
	
	IF (contador > 0) THEN
		-- Nesse caso, ja eh administrador, logo nao pode estar em outro tipo de funcionario
		RAISE EXCEPTION 'CPF ja cadastrado em algum sub-tipo de funcionario!';
		RETURN NULL;
	END IF;
	
	IF (contador = 0) THEN
		-- Chegou aqui eh porque so eh funcionario
		RETURN NEW;
	END IF;
	
END $$ LANGUAGE 'plpgsql';

CREATE TRIGGER limita_func
BEFORE INSERT OR UPDATE ON cozinheiro
FOR EACH ROW
EXECUTE PROCEDURE limita_funcoes_func();

CREATE TRIGGER limita_func
BEFORE INSERT OR UPDATE ON emp_corporativo
FOR EACH ROW
EXECUTE PROCEDURE limita_funcoes_func();

CREATE TRIGGER limita_func
BEFORE INSERT OR UPDATE ON administrador
FOR EACH ROW
EXECUTE PROCEDURE limita_funcoes_func();
