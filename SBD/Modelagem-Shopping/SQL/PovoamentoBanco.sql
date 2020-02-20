/* Funcionarios */
INSERT INTO funcionario VALUES 
('36719532090', 'Bianca', 1500.23, 'Feminino'),
('33363572093', 'Gustavo', 2421.89, 'Masculino'),
('99946014076', 'Alexandre', 954.32, 'Masculino'),
('18858588096', 'Thaynara', 3032.98, 'Feminino'),
('11253694001','Jonas', 1022.98,'Masculino'),
('23641006074','Caio', 1022.98,'Masculino'),
('78573340061','Andreia', 963.12,'Feminino'),
('79934291029','Viviane', 1011.43,'Feminino'),
('46741430040','Igor', 1321.87,'Masculino'),
('84281282009','Laura', 956.98,'Feminino'),
('54658993015','Brenda',6601.13 ,'Feminino'),
('26580013044','Lucas', 5401.12,'Masculino'),
('84688125011','Luan', 954.40,'Masculino'),
('90248190083','Pedro', 9800.21,'Masculino'),
('43251283014','Paulo', 15001.98,'Masculino'),
('40025970089','Gabriela', 6103.98,'Feminino'),
('56628297055','Lorena', 3200.14,'Feminino'),
('89970905007','Felipe', 1798.65,'Masculino'),
('13413850008','Renata', 1207.32,'Feminino'),
('39777613075','Karen', 1100.03,'Feminino'),
('47667502099','André', 11432.00,'Masculino'),
('10554465086','Yara', 4521.91,'Feminino'),
('08432126080','Ian', 4100.76,'Masculino'),
('19535481053','Yago', 1009.11,'Masculino'),
('34665157006','Álvaro', 990.87,'Feminino'),
('49980436093','Pietro', 999.17,'Masculino'),
('86075294040','Matheus', 960.54,'Masculino'),
('83824782049','Hélio', 9999.31,'Masculino'),
('29510298026','Ellen', 7601.32,'Feminino'),
('86281922042','Natália', 982.34,'Feminino'),
('21227697007','Kátia', 20387.96,'Feminino'),
('17998232021','Olímpio', 10340.12,'Masculino'),
('79619384008','Luciana', 1010.10,'Feminino');

/* Cozinheiros */
INSERT INTO cozinheiro VALUES
('36719532090','Comida mexicana'),
('33363572093','Comida italiana'),
('99946014076','Comida brasileira'),
('18858588096','Comida tailândesa'),
('11253694001','Comida chinesa'),
('23641006074','Comida chinesa'),
('78573340061','Comida chinesa'),
('79934291029','Comida francesa'),
('46741430040','Comida inglesa'),
('84281282009','Comida escocesa');

/* Administrador*/
INSERT INTO administrador VALUES
('54658993015','UFU'),
('26580013044','USP'),
('84688125011','USP'),
('90248190083','UFU'),
('43251283014','UFU'),
('40025970089','UFRJ'),
('56628297055','UFMG'),
('89970905007','Unicamp'),
('13413850008','Unitri'),
('39777613075','Pitágoras');

/* Empregado Corporativo */
INSERT INTO emp_corporativo VALUES
('47667502099','Desenvolvimento Backend'),
('10554465086','Recursos Humanos'),
('08432126080','SCRUM Master'),
('19535481053','Desenvolvimento Frontend'),
('34665157006','Marketing'),
('49980436093','DBA'),
('86075294040','Publicidade'),
('83824782049','Mídias digitais'),
('29510298026','Comunicação'),
('86281922042','Desenvolvimento Backend');

/* Organizador */
INSERT INTO organizador VALUES
('87398210051','Túlio','25 anos de experiência','Diversos'),
('26036009070','Thaís','4 anos de experiência','Culinária gourmet'),
('13073221077','Laurene','Sem experiência','Teatral'),
('71405483075','Suzan','4 anos de experiência','Culinária típica'),
('58476754027','Sólis','Sem experiência','Diversos'),
('55414248010','Vitor','3 anos de experiência','Musicais'),
('13895477010','Pablo','1 ano de experiência','Roda de conversa'),
('76059360017','Nádia','15 anos de experiência','Debates políticos'),
('06122195006','Lourenço','10 anos de experiência','Literários'),
('36194123087','Neymar','Sem experiência','Infantis');

/* Locatario */
INSERT INTO locatario VALUES
('05342221000161', 'Vitória', 15001.14),
('57838610000186', 'Tuyo', 20121.43),
('91132625000162', 'Ana', 98765.12),
('23750201000101', 'Ruan',9801.23),
('16026546000151', 'Carlos',78732.12),
('56010107000175', 'Murillo',5641.9),
('31356096000159', 'Paola',1223443.56),
('80728129000150', 'Celine',98762.12),
('79022274000131', 'Brenda',8765321.08),
('27217733000139', 'Thalyta',234541.34);

/* Departamento Administrativo */
INSERT INTO departamento_administrativo VALUES
(1, 'Gerenciamento de segurança'),
(2, 'Gerenciamento de normas CLT'),
(3, 'Gerenciamento financeiro'),
(4, 'Gerenciamento de contratos'),
(5, 'Gerenciamento de garantias legais'),
(6, 'Gerenciamento de marketing'),
(7, 'Gerencimento de comunicação'),
(8, 'Gerenciamento de pessoas'),
(9, 'Gerenciamento de eventos'),
(10, 'Gerenciamento de comércios gerais');

/* Evento */
INSERT INTO evento VALUES
('2017-06-14','Roda de Samba 1ª Edição','87398210051'),
('2021-04-09','Patinação no Gelo','58476754027'),
('2014-03-29','Festival Churros Gourmet','26036009070'),
('1990-10-10','Debate presidencial 1990','76059360017'),
('2018-09-11','Feira de Livros','06122195006'),
('2018-12-27','Bienal','58476754027'),
('2019-08-02','Show Nando Reis','55414248010'),
('2020-11-07','Debate acerca da diversidade','13895477010'),
('2000-02-11','Xuxa só para baixinhos','36194123087'),
('2018-06-23','Roda de Samba 2ª Edição','87398210051');

/* Tipo de comodo */
INSERT INTO tipo_comodo VALUES	
(1, 100,3000 , 1),
(2, 150, 5000, 1),
(3, 250, 7000, 1),
(4, 300, 9000, 1),
(5, 350, 12000, 2),
(6, 400, 15000, 2),
(7, 450, 16000, 2),
(8, 500, 17000, 2),
(9, 550, 18000, 2),
(10, 600, 2000, 2);

/* Empresa Corporativa */
INSERT INTO empresa_corporativa VALUES
('16178371000106','Software S/A','2012-05-10', 1827431.32, 4),
('16158189000185','Mania Software','2010-09-11',9874354.21, 4),
('80469624000191','Bolsa de Valores','1990-07-20', 28382103.43, 5),
('41904913000110','Marketing S/A','2000-02-20', 132483.23, 5),
('74586361000106','Estatística Market','1970-03-22', 9883421.21, 5),
('97065028000149','Viana Corporation','1999-02-21', 4583012.44, 6),
('19089124000113','Colarinho Branco S/A','1998-12-21', 7874302.87, 7),
('55384212000101','Moura Corporation','2017-07-17', 234541.54, 8),
('39529457000123','Irmãos Kenedy Corporation','2018-09-24', 8734320.54,5),
('46115518000171','Transactions S/A','2018-01-09', 99982.12,6);

/* Cinema */
INSERT INTO cinema VALUES
('Centerplex Cinema', 6434132.15,6),
('United Cinemas', 423423.76,6),
('Kinoplex', 123232.87,6),
('Cinemais', 3489209.12,6),
('Cinemark', 4458549.54,7),
('Cinepólis', 323231.99,7),
('Casa de Cinema Brasil', 212324.21,5),
('GNC Lindóia', 650324.21,5),
('PMC Cinemas', 745443.54,4),
('Microcine Cinema', 98483.55,4);

/* Sala */
INSERT INTO sala VALUES
('Centerplex Cinema', 250, false,'Simples', false),
('United Cinemas', 250, false,'Reclinável', true),
('Kinoplex', 250, false,'Simples', true),
('Cinemais',300 , true,'Reclinável', true),
('Cinemark', 300, true,'Reclinável', false),
('Cinepólis', 300, true,'Simples', false),
('Casa de Cinema Brasil', 200, false,'Simples', true),
('GNC Lindóia', 200, false,'Simples', false),
('PMC Cinemas', 150, false,'Reclinável', true),
('Microcine Cinema', 150, false,'Simples', false);

/* Estacionamento */
INSERT INTO estacionamento VALUES
(1, 50),
(2, 100),
(3, 150),
(4, 200),
(5, 250),
(6, 280),
(7, 300),
(8, 310),
(9, 350),
(10,400);

/* Banco */
INSERT INTO banco VALUES
('Banco do Brasil',1),
('Bradesco',1),
('Santander',1),
('Caixa',1),
('Itaú',1),
('Banco Cruzeiro do Sul',1),
('Banco Safra',1),
('BNDES',2),
('Citibank Brasil',2),
('Banco do Nordeste',2);

/* Praça de alimentação */
INSERT INTO praca_alimentacao VALUES	
(1, 200),
(2, 250),
(3, 150),
(4, 20),
(5, 25),
(6, 28),
(7, 30),
(8, 32),
(9, 34),
(10, 35); 

/* Restaurante */
INSERT INTO restaurante VALUES
('92629249000189', 'Bodega 1900', 'Espanhola', 5, 2),
('92170075000139', 'Antiquarius', 'Portuguesa', 4, 2),
('05015765000119', 'McDonalds', 'Diversificado', 2, 1),
('41025895000104', 'Grand China', 'Diversificado', 2, 1),
('26774162000170', 'Starbucks', 'Diversificado', 2, 1),
('81316498000106', 'Pizza Hut', 'Diversificado', 2, 1),
('05438563000180', 'Chipotle Mexican', 'Mexicana', 4, 2),
('03626133000166', 'Koh Pee Pee', 'Tailandesa', 4, 2),
('58175453000139', 'Vecchio Sogno', 'Italiana', 3, 1),
('23932684000165', 'Mangai', 'Brasileira', 3, 1); 

/* Aluga (Locatario aluga um tipo de comodo) */
INSERT INTO aluga VALUES
(1, '79022274000131', 2,'2001-09-24','2025-09-24'),
(2, '31356096000159', 2,'2018-12-20','2019-12-20'),
(3, '31356096000159', 2,'2016-07-08','2019-07-08'),
(4, '23750201000101', 2,'2016-11-11','2018-11-11'),
(5, '91132625000162', 3,'2007-03-22','2017-03-22'),
(6, '91132625000162', 5,'2019-01-01','2023-01-01'),
(7, '91132625000162', 4,'2018-09-11','2020-09-11'),
(8, '57838610000186', 4,'2000-02-20','2010-02-20'),
(9, '79022274000131', 1,'1987-04-01','1990-04-01'),
(10, '79022274000131', 8,'2010-06-21','2020-06-21');

/* Trabalha em restaurante */
INSERT INTO trabalha_restaurante VALUES
('18858588096','03626133000166'),
('36719532090','05438563000180'),
('11253694001','41025895000104'),
('78573340061','41025895000104'),
('23641006074','41025895000104'),
('99946014076','23932684000165'),
('84281282009','92629249000189'),
('33363572093','26774162000170'),
('79934291029','92629249000189'),
('46741430040','92629249000189');

/* Trabalha em empresa corporativa */
INSERT INTO trabalha_emp_corporativa VALUES
('47667502099','55384212000101'),
('10554465086','80469624000191'),
('08432126080','16158189000185'),
('19535481053','16178371000106'),
('34665157006','46115518000171'),
('49980436093','80469624000191'),
('86075294040','46115518000171'),
('83824782049','46115518000171'),
('29510298026','74586361000106'),
('86281922042','16158189000185');

/* Trabalha em departamento administrativo */
INSERT INTO trabalha_departamento_adm VALUES
('54658993015',1),
('26580013044',1),
('84688125011',1),
('90248190083',2),
('43251283014',1),
('40025970089',4),
('56628297055',3),
('89970905007',8),
('13413850008',8),
('39777613075',8);
