-- ----------------------------------------------------------
-- mdb tools - a library for reading ms access database files
-- copyright (c) 2000-2011 brian bruns and others.
-- files in libmdb are licensed under lgpl and the utilities under
-- the gpl, see copying.lib and copying files respectively.
-- check out http://mdbtools.sourceforge.net
-- ----------------------------------------------------------

set client_encoding = 'utf-8';

drop table if exists "netgeo"."site";
create table "netgeo"."site"
 (
	"identifiant"			text  not null, 
	"id_point"			text  not null, 
	"nom"			text , 
	"code"			text , 
	"type_fonc"			text , 
	"type_struc"			text , 
	"gestionnaire"			text , 
	"proprietaire"			text , 
	"adresse"			text , 
	"code_postal"			text , 
	"ville"			text , 
	"coord_x"			double precision, 
	"coord_y"			double precision, 
	"etat"			text , 
	"crea_auteur"			text , 
	"crea_date"			integer, 
	"modif_auteur"			text , 
	"modif_date"			integer, 
	"emprise"			text , 
	"statut_occup"			text , 
	"adrs_adduction"			text , 
	"acces_jour"			text , 
	"acces_nuit"			text , 
	"adresse_sap"			text , 
	"adresse_pbp"			text , 
	"nbre_foyers"			text , 
	"num_voirie"			text , 
	"extension"			text , 
	"type_voirie"			text , 
	"code_voirie"			text , 
	"nom_de_voie"			text , 
	"suffixes"			text , 
	"code_fantoir"			text , 
	"code_insee"			text , 
	"nb_micro_modules"			text , 
	"info_nbr_copro"			text , 
	"micro_modules_comite"			text , 
	"quartier"			text , 
	"ilot"			text , 
	"parcelle"			text 
);


-- create relationships ...
