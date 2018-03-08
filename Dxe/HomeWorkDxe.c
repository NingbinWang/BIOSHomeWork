///**********************************************************************
//**********************************************************************
//**                                                                  **
//**        (C)Copyright 1985-2010, American Megatrends, Inc.         **
//**                                                                  **
//**                       All Rights Reserved.                       **
//**                                                                  **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093        **
//**                                                                  **
//**                       Phone: (770)-246-8600                      **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include <AmiDxeLib.h>
#include <OEMLib.h>
#include "..\HomeWork.h"
EFI_STATUS HomeWorkDxeEntryPoint(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
)
{
    EFI_GUID                GuidHob = HOB_LIST_GUID;
    EFI_STATUS              Status;
    HOMEWORK_HOB *Homeworkhob=NULL;
    EFI_GUID    HomeworkHobGuid=HOMEWORK_HOB_GUID;
    VOID       *pHobList = NULL;
    
    
    
	InitAmiLib(ImageHandle,SystemTable);
	OEM_TRACE("entry homeworkDXE module\n");
	
	pHobList = GetEfiConfigurationTable(SystemTable, &GuidHob);
	if (!pHobList) return EFI_NOT_READY;
	
	Homeworkhob = (HOMEWORK_HOB*)pHobList;
	while (!EFI_ERROR(Status = FindNextHobByType(EFI_HOB_TYPE_GUID_EXTENSION, &Homeworkhob)))
	{
	        if (guidcmp(&(*Homeworkhob).EfiHobGuidType.Name, &HomeworkHobGuid) == 0)
	            break;
	}
	   if (EFI_ERROR(Status)) 
	  {
	      return EFI_NOT_FOUND;
	   }else{
	         OEM_TRACE("data=%d\n",Homeworkhob->homeworkdata);
	   }
	
	return EFI_SUCCESS;
}

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**        (C)Copyright 1985-2010, American Megatrends, Inc.         **
//**                                                                  **
//**                       All Rights Reserved.                       **
//**                                                                  **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093        **
//**                                                                  **
//**                       Phone: (770)-246-8600                      **
//**                                                                  **
//**********************************************************************
//**********************************************************************
