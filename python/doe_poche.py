#!/bin/env python3

import os
import sys
import shutil
import xlwt

if (sys.argv[0]!=''):
	path=sys.argv[0]
	os.chdir(path)
else:
	path=os.curdir

#path="Y:\\01 - CRI 13\\10-DOE\\01-LIVRABLES" 
poche=sys.argv[2]
nro=sys.argv[0]
ext=nro+"_EXT01"
date="150320"	
plaque=sys.argv[1]


root = "501_DOE_CTR"+poche+"_"+ext+"_"+date+"_INDA"
os.mkdir(root)
os.chdir(root)
os.mkdir("415_FAT_TVX_"+nro)
os.mkdir("515_BASE_CTR"+poche+"_DOE_"+nro+"_INDA")
os.mkdir("521_PHOTOS_CTR"+poche+"_TVX_"+nro+"_INDA")
os.mkdir("530_INF_GC_PLN_TVX_"+nro+"_INDA")
os.mkdir("550_DOSS_INFRA_TVX_"+nro+"_"+nro+"_INDA")
dossier="580_DM_TVX_"+nro+"_INDA"+os.sep+"581_DM_TVX_CTR"+poche+"_"+nro+"_INDA"+os.sep+"CTR_"+plaque+"_"+poche+"_INDA"
os.makedirs(dossier)
os.chdir(dossier)

wb=xlwt.Workbook()
ws=wb.add_sheet('Feuill1')

wb.save("MESURE_CTR_"+plaque+"_"+poche+"_INDA.xls")
#shutil.copy2("C:\\Users\\fnjeneza\\Documents\\programmes\\script\\591_JUSTIFICATION.xls","MESURE_CTR_"+plaque+"_"+poche+"_INDA.xls")
os.chdir("..")
wb.save("MESURE_POCHE_"+plaque+"_"+poche+"_INDA.xls")
#shutil.copy2("C:\\Users\\fnjeneza\\Documents\\programmes\\script\\591_JUSTIFICATION.xls","MESURE_POCHE_"+plaque+"_"+poche+"_INDA.xls")
os.chdir(".."+os.sep+"..")
dossier="591_JUSTIFICATION_DOE_CTR"+poche+"_"+nro+"_"+date+"_INDA"
os.mkdir(dossier)
os.chdir(dossier)
wb.save("JUSTIFICATION_DOE_CTR"+poche+"_"+nro+"_"+date+"_INDA.xls")
#shutil.copy2("C:\\Users\\fnjeneza\\Documents\\programmes\\script\\591_JUSTIFICATION.xls","591_JUSTIFICATION_DOE_CTR"+poche+"_"+nro+"_"+date+"_INDA.xls")

