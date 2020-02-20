/*
DROP ROLE josefina;
DROP ROLE jose; 

REVOKE ALL ON DATABASE postgres FROM normal_user, admin_user;
REVOKE ALL ON SCHEMA shopping FROM normal_user, admin_user;

DROP ROLE normal_user;
DROP ROLE admin_user;
*/

/* Cria os grupos admin e usuario e concede permissoes */
CREATE ROLE admin_user WITH SUPERUSER CREATEDB CREATEROLE INHERIT NOLOGIN NOREPLICATION CONNECTION LIMIT -1;
CREATE ROLE normal_user WITH NOSUPERUSER NOCREATEDB NOCREATEROLE INHERIT NOLOGIN NOREPLICATION CONNECTION LIMIT -1; 

GRANT CONNECT ON DATABASE postgres TO admin_user, normal_user;
GRANT USAGE ON SCHEMA shopping TO admin_user, normal_user;

-- Retira todas as permissoes do normal_user
REVOKE INSERT, UPDATE, SELECT, DELETE ON
	administrador, aluga, banco, cinema, cozinheiro,
	departamento_administrativo, emp_corporativo,
	empresa_corporativa, estacionamento, evento,
	funcionario, locatario, organizador,
	praca_alimentacao, restaurante, sala, tipo_comodo,
	trabalha_departamento_adm, trabalha_emp_corporativa,
	trabalha_restaurante
	FROM normal_user;
	
-- Concede algumas permissoes pro normal_user
GRANT SELECT ON 
	administrador, aluga, banco, cinema, cozinheiro,
	departamento_administrativo, emp_corporativo,
	empresa_corporativa, estacionamento, evento,
	funcionario, locatario, organizador,
	praca_alimentacao, restaurante, sala, tipo_comodo,
	trabalha_departamento_adm, trabalha_emp_corporativa,
	trabalha_restaurante
	
	TO normal_user;

-- Concede todas as permissoes para admin_user
GRANT INSERT, UPDATE, SELECT, DELETE ON
	administrador, aluga, banco, cinema, cozinheiro,
	departamento_administrativo, emp_corporativo,
	empresa_corporativa, estacionamento, evento,
	funcionario, locatario, organizador,
	praca_alimentacao, restaurante, sala, tipo_comodo,
	trabalha_departamento_adm, trabalha_emp_corporativa,
	trabalha_restaurante
	TO admin_user;

/* Cria os primeiros usuarios e concede permissoes*/
CREATE ROLE josefina WITH LOGIN ENCRYPTED PASSWORD '123';
CREATE ROLE jose WITH LOGIN ENCRYPTED PASSWORD '123';

GRANT admin_user TO josefina;
GRANT normal_user TO jose;

/* Inserir manualmente o jose e a josefina em login! */


