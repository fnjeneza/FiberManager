#!/bin/env python3

import os

path="Y:\\01 - CRI 13\\10-DOE\\01-LIVRABLES\\501_DOE_CTR23_CRI13_EXT01_150220_INDA"
poche="23"
nro="CRI13"
ctr="CTR"+poche
date="150220"
plaque="PLA13_014"

os.chdir(path)
dossier = "415_FAT_TVX_"+nro
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")

dossier = "515_BASE_"+ctr+"_DOE_"+nro+"_INDA"
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")

dossier = "521_PHOTOS_"+ctr+"_TVX_"+nro+"_INDA"
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")
else 
	tb=dossier+os.sep+"PHOTOS_"+ctr+"_TVX_"+nro+"_TB.jpg"
	th=dossier+os.sep+"PHOTOS_"+ctr+"_TVX_"+nro+"_TH.jpg"
	if not (os.path.exists(tb) & os.path.isfile(tb)):
		print (tb+".{jpg,JPG} manquant ou mal nommé")
	if not (os.path.exists(th) & os.path.isfile(th)):
		print (th+".{jpg,JPG} manquant ou mal nommé")
	

dossier = "530_INF_GC_PLN_TVX_"+nro
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")
else:
	counter=1
	isFound=False
	while(counter<1000 & isFound==False):
		num=""+counter
		if(os.path.exists(dossier+os.sep+"INF_GC_PLN_"+num.zfill(3)+"_TVX_"+nro+"_INDA") & os.path.isfile(dossier+os.sep+"INF_GC_PLN_"+num.zfill(3)+"_TVX_"+nro+"_INDA")):
			isFound=True
		counter+=1	
	if not(isFound):
		print("INF_GC_PLN_[0-9][0-9][0-9]_TVX_"+nro+"_INDA"+" manquant ou mal nommé\n")
	
dossier = "550_DOSS_INFRA_TVX_"+nro+"_INDA"
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")
else:
	file="TAB_INFRA_TVX_"+nro+"_INDA.xls"
	path=dossier+os.sep+file
	if not (os.path.exists(path) & os.path.isfile(path))
		print(file+" manquant ou mal nommé\n")

dossier = "580_DM_TVX_"+nro+"_INDA"
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")

dossier = "591_JUSTIFICATION_DOE_"+ctr+"_"+nro+"_"+date+"_INDA"
if not (os.path.exists(dossier) & os.path.isdir(dossier)):
	print (dossier+" manquant ou mal nommé \n")
