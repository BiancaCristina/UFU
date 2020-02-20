CREATE SCHEMA shopping; 
SET SEARCH_PATH TO shopping;

/* Criacao das tabelas basicas */
CREATE TABLE funcionario (
	cpf			varchar(11),
	nome		varchar(30),
	salario		float	NOT NULL,
	genero		varchar(15)	CHECK (genero = 'Feminino' OR genero = 'Masculino') NOT NULL,

	CONSTRAINT funcionario_pk PRIMARY KEY (cpf)
);

CREATE TABLE cozinheiro (
	cpf				varchar(11),
	especialidade	varchar(20)		NOT NULL,
	
	CONSTRAINT cozinheiro_pk PRIMARY KEY (cpf),
	CONSTRAINT funcionario_fk FOREIGN KEY (cpf)
		REFERENCES funcionario (cpf) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE administrador (
	cpf			varchar(11),
	faculdade	varchar(25)		NOT NULL,
	
	CONSTRAINT adm_pk PRIMARY KEY (cpf),
	CONSTRAINT funcionario_fk FOREIGN KEY (cpf)
		REFERENCES funcionario (cpf) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE emp_corporativo (
	cpf					varchar(11),
	area_atuacao		varchar(25) 	NOT NULL,
	
	CONSTRAINT emp_corp_pk PRIMARY KEY (cpf),
	CONSTRAINT funcionario_fk FOREIGN KEY (cpf)
		REFERENCES funcionario (cpf) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE organizador (
	cpf					varchar(11),
	nome				varchar(30)		NOT NULL,
	exp_profissional	varchar(50),
	tipos_eventos		varchar(50)		NOT NULL,
	
	CONSTRAINT organizador_pk PRIMARY KEY (cpf)
);

CREATE TABLE locatario (
	cnpj			varchar(14),
	nome			varchar(20),
	renda_anual		float,
	
	CONSTRAINT locatario_pk PRIMARY KEY (cnpj)
);

CREATE TABLE departamento_administrativo (
	codigo			smallint,
	descricao		varchar(40)		NOT NULL,
	
	CONSTRAINT departamento_adm_pk PRIMARY KEY (codigo)
);

CREATE TABLE evento (
	data				date,	
	nome				varchar(50),
	cpf_organizador			varchar(11),
	
	CONSTRAINT evento_pk PRIMARY KEY (data, nome),
	CONSTRAINT evento_fk FOREIGN KEY (cpf_organizador)
		REFERENCES organizador (cpf) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE tipo_comodo (
	numero_identificador 		smallint,
	tamanho						smallint		NOT NULL,
	preco						float			NOT NULL,
	localizacao					smallint		NOT NULL,  	 -- Indica o andar!
	
	CONSTRAINT tipo_comodo_pk PRIMARY KEY (numero_identificador)
);

CREATE TABLE empresa_corporativa (
	cnpj			varchar(14),
	nome			varchar(40)			NOT NULL,
	data_fundacao 	date,
	faturamento		float,
	tipo_comodo 	smallint,
	
	CONSTRAINT empresa_pk PRIMARY KEY (cnpj),
	CONSTRAINT emp_corp_fk FOREIGN KEY (tipo_comodo)
		REFERENCES tipo_comodo(numero_identificador) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE cinema (
	nome			varchar(40),
	faturamento		float,
	tipo_comodo		smallint	NOT NULL,
	
	CONSTRAINT cinema_pk PRIMARY KEY (nome),
	CONSTRAINT cinema_fk FOREIGN KEY (tipo_comodo)
		REFERENCES tipo_comodo (numero_identificador) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE sala (
	nome				varchar(40),
	tamanho				smallint,
	ar_condicionado		boolean			NOT NULL,
	tipo_cadeira		varchar(10)		CHECK (tipo_cadeira = 'Simples' OR tipo_cadeira = 'Reclinável') NOT NULL,
	area_vip			boolean			NOT NULL,
	
	CONSTRAINT sala_pk PRIMARY KEY (nome, tamanho),
	CONSTRAINT sala_fk FOREIGN KEY (nome)
		REFERENCES cinema (nome) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE estacionamento (
	numero_id		smallint,
	area			integer,
	
	CONSTRAINT estacionamento_pk PRIMARY KEY (numero_id)
);

CREATE TABLE banco (
	nome			varchar(40),
	localizacao		smallint		NOT NULL,  -- Indica o andar!
	
	CONSTRAINT banco_pk PRIMARY KEY (nome)
);

CREATE TABLE praca_alimentacao (
	andar		smallint,
	tamanho		integer,
	
	CONSTRAINT praca_pk	PRIMARY KEY (andar)
);

CREATE TABLE restaurante (
	cnpj				varchar(14),
	nome				varchar(20),
	comidas_tipicas		varchar(50),
	tipo_comodo			smallint		NOT NULL,
	praca				smallint		NOT NULL,
	
	CONSTRAINT restaurante_pk PRIMARY KEY (cnpj),
	CONSTRAINT restaurante_fk1 FOREIGN KEY (tipo_comodo)
		REFERENCES tipo_comodo (numero_identificador)ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT restaurante_fk2 FOREIGN KEY (praca)
		REFERENCES praca_alimentacao (andar) ON UPDATE CASCADE ON DELETE CASCADE
);

/* Criacao das tabelas que relacionam as entidades */

CREATE TABLE aluga (
	codigo			smallint,
	cnpj			varchar(14)		NOT NULL,	
	tipo_comodo		smallint		NOT NULL,
	dataInicio		date			NOT NULL,
	dataFim			date			NOT NULL,
	
	CONSTRAINT aluga_pk PRIMARY KEY (codigo),
	CONSTRAINT aluga_fk1 FOREIGN KEY (cnpj)
		REFERENCES locatario (cnpj) ON UPDATE CASCADE,
	CONSTRAINT aluga_fk2 FOREIGN KEY (tipo_comodo)
		REFERENCES tipo_comodo (numero_identificador) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE trabalha_restaurante (
	-- Apenas o cozinheiro pode trabalhar no restaurante
	cpf			varchar(11),
	cnpj		varchar(14),
	
	CONSTRAINT trab_rest_pk PRIMARY KEY (cpf, cnpj),
	CONSTRAINT trab_rest_fk1 FOREIGN KEY (cpf)
		REFERENCES cozinheiro (cpf) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT trab_rest_fk2 FOREIGN KEY (cnpj)
		REFERENCES restaurante (cnpj) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE trabalha_departamento_adm (
	-- Apenas o administrador pode trabalhar no departamento administrativo
	cpf			varchar(11),
	codigo 		smallint,
	
	CONSTRAINT trab_depar_adm_pk PRIMARY KEY (cpf, codigo),
	CONSTRAINT trab_depar_adm_fk1 FOREIGN KEY (cpf)
		REFERENCES administrador (cpf) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT trab_depar_adm_fk2 FOREIGN KEY (codigo)
		REFERENCES departamento_administrativo (codigo) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE trabalha_emp_corporativa (
	-- Apenas o empregado corporativo pode trabalhar na empresa corporativa
	cpf			varchar(11),
	cnpj		varchar(14),
	
	CONSTRAINT trab_emp_corp_pk PRIMARY KEY (cpf, cnpj),
	CONSTRAINT trab_emp_corp_fk1 FOREIGN KEY (cpf)
		REFERENCES emp_corporativo (cpf) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT trab_emp_corp_fk2 FOREIGN KEY (cnpj)
		REFERENCES empresa_corporativa (cnpj) ON UPDATE CASCADE ON DELETE CASCADE
);


