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
#include <Efi.h>

VOID HomeWorkDxeHobnotify(
        IN EFI_EVENT                    Event,
        IN VOID                         *Context   
)
{
    EFI_GUID                GuidHob = HOB_LIST_GUID;
     HOMEWORK_HOB            *Homeworkhob=NULL;
     EFI_GUID                 HomeworkHobGuid=HOMEWORK_HOB_GUID;
     VOID                    *pHobList = NULL;
     EFI_STATUS              Status;
     pHobList = GetEfiConfigurationTable(pST, &GuidHob);
     if (!pHobList) return;
         
     Homeworkhob = (HOMEWORK_HOB*)pHobList;
     while (!EFI_ERROR(Status = FindNextHobByType(EFI_HOB_TYPE_GUID_EXTENSION, &Homeworkhob)))
     {
         if (guidcmp(&(*Homeworkhob).EfiHobGuidType.Name, &HomeworkHobGuid) == 0)
                     break;
     }
     if (EFI_ERROR(Status)) 
     {
          return;
     }else{
              OEM_TRACE("data=%d\n",Homeworkhob->homeworkdata);
     }
     
     pBS->SignalEvent(Event);
}

EFI_STATUS HomeWorkDxeEntryPoint(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
)
{
    
    EFI_STATUS              Status;
    EFI_EVENT              homeworkevent;
    UINTN                    index=0;
    
    
	InitAmiLib(ImageHandle,SystemTable);
/*	
	Status = gBS->CreateEvent(
	         EVT_NOTIFY_SIGNAL,
	         TPL_CALLBACK,
	         HomeWorkDxeHobnotify,
	        )
*/	
	
	Status = pBS->CreateEvent(
	             EVT_NOTIFY_WAIT,
	             TPL_NOTIFY,
	             (EFI_EVENT_NOTIFY)HomeWorkDxeHobnotify,
	             (VOID*)NULL,
	             &homeworkevent
	            );
	
	Status =  pBS->WaitForEvent(1,&homeworkevent,&index);
	
	
	
	
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
