/* Consultas */
-- 1) Mostrar quantos alugueis de um determinado locatario vencem após a data atual
SELECT 
	COUNT(al.codigo),
	lo.nome
	
FROM
	aluga AS al INNER JOIN locatario lo ON al.cnpj = lo.cnpj
	
WHERE
	al.datafim > current_date
	
GROUP BY lo.nome;


-- 2) Seleciona nome de quais funcionarios possui salario maior que a media de salarios (USA AVG) --> FOI PRA INTERFACE! 
SELECT 
	f.nome
	
FROM
	funcionario AS f
	
GROUP BY f.nome, f,salario
HAVING f.salario > (
			SELECT AVG(funcionario.salario)
			FROM funcionario
		   ); 

-- 3) Seleciona  a soma do faturamento de todos os cinemas (USA SUM)
SELECT
	SUM(c.faturamento)
	
FROM
	cinema AS c;

-- 4) Seleciona qual departamento administrativo que mais possui funcionarios (USA >= ALL)
SELECT
	t_dpto.codigo
	
FROM
	trabalha_departamento_adm AS t_dpto
	
GROUP BY t_dpto.codigo
HAVING COUNT(*) >= ALL (
				SELECT COUNT(t_dpto.codigo)
				FROM trabalha_departamento_adm AS t_dpto
				GROUP BY t_dpto.codigo
			);


-- 5) Seleciona (nome) qual locatario aluga menos tipo_comodo (USA MIN) -> FOI COLOCADA NA INTERFACE!
SELECT 
	lo.nome
	
FROM 
	aluga al INNER JOIN locatario lo ON al.cnpj = lo.cnpj
	
GROUP BY lo.nome

HAVING COUNT(*) <= ALL	(
				SELECT COUNT(aluga.cnpj) 
				FROM aluga 
				GROUP BY aluga.cnpj
			);

-- 6) Seleciona o maior tipo de comodo disponivel
SELECT
	MAX(tipo.tamanho)
	
FROM
	tipo_comodo AS tipo;


-- 7) Mostra a quantidade de administradores agrupados por faculdade
SELECT 
	adm.faculdade,
	COUNT(adm.faculdade)
	
FROM 
	administrador AS adm
	
GROUP BY adm.faculdade;


-- 8) Mostre o nome de funcionario que nao seja cozinheiro, empregado corporativo ou administrador? --> FOI COLOCADA NA INTERFACE

SELECT DISTINCT
	f.nome

FROM
	funcionario AS f
	
WHERE
	f.cpf NOT IN (SELECT cozinheiro.cpf FROM cozinheiro) AND
	f.cpf NOT IN (SELECT emp_corporativo.cpf FROM emp_corporativo) AND
	f.cpf NOT IN (SELECT administrador.cpf FROM administrador); 

-- 10) Selecione quais cinemas possuem salas com ar condicionado e area vip
SELECT
	c.nome
	
FROM
	cinema AS c,
	sala AS s
	
WHERE
	s.nome = c.nome AND
	s.ar_condicionado= true AND
	s.area_vip = true;

-- 11) Selecione qual o locatario mais rico (USA MAX) --> FOI PRA INTERFACE!
SELECT 
	lo.nome
	
FROM
	locatario AS lo
	
WHERE
	lo.renda_anual >= 	(
					SELECT MAX(lo.renda_anual)
					FROM locatario AS lo
				);


-- 12) Seleciona o primeiro evento que ja ocorreu no shopping e seus organizadores (USA MIN)
SELECT
	e.nome, o.nome
	
FROM
	evento e, organizador o
	
WHERE
	e.cpf_organizador = o.cpf AND e.data = (SELECT MIN(e.data)
											FROM evento AS e
											);

/* 
	13) De acordo com o artigo 461 da Consolidação das Leis do Trabalho (CLT),  sendo idêntica a função, a todo trabalho de igual valor, prestado ao mesmo empregador, na mesma localidade, corresponderá igual salário, sem distinção de sexo, nacionalidade ou idade.
	Dessa forma, nesse Shopping, cozinheiros que possuem a mesma especialidade devem receber o mesmo salário independente do sexo (fator discriminante de funcionário). 
	Sendo assim, essa consulta verifica se existem diferenças salariais entre funcionárias e funcionários que são cozinheiros e possuem a mesma especialidade. 
*/

-- Cria visões que separam as tabelas de cozinheiro por sexo
CREATE MATERIALIZED VIEW cozinheiras AS	
	SELECT
		f.nome,
		f.salario,
		coz.cpf,
		coz.especialidade
		
	FROM
		funcionario AS f,
		cozinheiro AS coz
		
	WHERE
		f.cpf = coz.cpf AND
		f.genero = 'Feminino'; 
		
CREATE MATERIALIZED VIEW cozinheiros AS	
	SELECT
		f.nome,
		f.salario,
		coz.cpf,
		coz.especialidade
		
	FROM
		funcionario AS f,
		cozinheiro AS coz
		
	WHERE
		f.cpf = coz.cpf AND
		f.genero = 'Masculino'; 
		
-- Consulta propriamente dita:

SELECT 
	cf.nome,
	cf.salario,
	cm.nome,
	cm.salario
	
FROM
	cozinheiras cf INNER JOIN cozinheiros cm ON cf.especialidade = cm.especialidade
	
WHERE 
	cf.salario <> cm.salario; 
	

/* 14) Consulta quais os eventos dos proximos "x" dias organizados pelo organizador "y" */
SELECT
	ev.nome,
	org.nome
	
FROM 
	evento ev INNER JOIN organizador org ON ev.cpf_organizador = org.cpf
	
WHERE
	ev.data > current_date + interval '48 hours' AND
	ev.cpf_organizador = '11111111111';

/* 15)  A renda anual dos 3 primeiros locatarios com o maiores comodos. */
SELECT l.nome,l.renda_anual,tc.tamanho
FROM locatario l, aluga a, tipo_comodo tc
WHERE a.cnpj = l.cnpj AND tc.numero_identificador = a.tipo_comodo
GROUP BY l.nome,l.renda_anual,tc.tamanho
ORDER BY tc.tamanho DESC
LIMIT 3

/*16) Quantos restaurantes tem por andar? */
SELECT count(r.cnpj) AS qtd_restaurantes, tc.localizacao
FROM tipo_comodo tc, restaurante r
WHERE r.tipo_comodo = tc.numero_identificador
GROUP BY (tc.localizacao);

/* 17) Qual a media de renda com restaurantes do shopping? */
-- Verificar se ta funcionando ok
SELECT AVG(tc.preco)
FROM tipo_comodo tc, restaurante r
WHERE tc.numero_identificador = r.tipo_comodo;

/* 18) Renda total com os locatariosdo shopping?*/
-- Verificar se ta funcionando ok
SELECT SUM(tc.preco)
FROM aluga a, tipo_comodo tc
WHERE a.tipo_comodo = tc.numero_identificador;

/* 19) O nome da empresa mais velha, os seus funcioanrio e suas áreas de atuaç?o.*/
SELECT ec.nome, f.nome, emp.area_atuacao
FROM empresa_corporativa ec, funcionario f, trabalha_emp_corporativa tec, emp_corporativo emp
WHERE ec.cnpj = tec.cnpj AND f.cpf = tec.cpf AND emp.cpf = f.cpf AND ec.data_fundacao = 
			(SELECT MIN(data_fundacao)
			 FROM empresa_corporativa
			);

/* 20) A renda anual dos 3 primeiros locatarios com o maiores comodos.*/ 
SELECT l.nome,l.renda_anual,tc.tamanho
FROM locatario l, aluga a, tipo_comodo tc
WHERE a.cnpj = l.cnpj AND tc.numero_identificador = a.tipo_comodo
GROUP BY l.nome,l.renda_anual,tc.tamanho
ORDER BY tc.tamanho DESC
LIMIT 3

/* 21) Quantidade de funcionarios que trabalham na empresa corporativa de maior renda ou na de maior tamanho */
SELECT DISTINCT
	emp.nome,
	COUNT(t_emp.cpf) AS qtd_funcionarios
	
FROM
	empresa_corporativa emp INNER JOIN trabalha_emp_corporativa t_emp ON emp.cnpj = t_emp.cnpj

WHERE
	emp.faturamento >= ALL	(
								SELECT MAX(emp.faturamento)
								FROM empresa_corporativa AS emp
							) OR
	emp.tipo_comodo = (
							SELECT MAX(tc.numero_identificador)
							FROM tipo_comodo tc INNER JOIN empresa_corporativa emp ON tc.numero_identificador = emp.tipo_comodo
					  )
GROUP BY emp.nome; 

/* 21) Mostra a media dos salarios e o nome da empresa corporativa com o maior tamanho? */

SELECT  eprc.nome,AVG(f.salario)
FROM empresa_corporativa eprc, funcionario f, emp_corporativo ec, tipo_comodo tc, trabalha_emp_corporativa tec
WHERE f.cpf = ec.cpf AND ec.cpf = tec.cpf AND eprc.cnpj = tec.cnpj AND tc.numero_identificador = eprc.tipo_comodo AND
		tc.tamanho = (SELECT MAX(tc.tamanho)
					  FROM tipo_comodo tc, empresa_corporativa eprc
					  WHERE tc.numero_identificador = eprc.tipo_comodo)
GROUP BY f.nome, eprc.nome;

/* 22) Folha de pagamento do menor restaurante do Shopping */
SELECT 
	r.nome,
	SUM(f.salario)
	
FROM
	restaurante r INNER JOIN trabalha_restaurante t_r ON r.cnpj = t_r.cnpj
		INNER JOIN funcionario f ON f.cpf = t_r.cpf

WHERE 
	r.tipo_comodo = (SELECT MIN(tc.numero_identificador)
					 FROM tipo_comodo AS tc, restaurante AS r
					 WHERE r.tipo_comodo = tc.numero_identificador)
	
GROUP BY r.nome; 
