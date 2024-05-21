use loja;
create table pessoas (
cod_pessoa int primary key auto_increment,
nom_pessoa varchar(50),
dta_nasc_pessoa date);
insert into  pessoas values (2,'Nair','1963/11/01');
insert into pessoas values (1,'Catarina','1934/07/16');
insert into pessoas values (3,'Maria','2009/09/10');

select * from pessoas;

CREATE TABLE ALUNO (
		RA int( 9),
		NOTA decimal(3,1) ) ;
INSERT INTO ALUNO VALUES (2,4) ;
INSERT INTO ALUNO VALUES (1,9) ;
INSERT INTO ALUNO VALUES (3,7) ;

Select * from aluno;