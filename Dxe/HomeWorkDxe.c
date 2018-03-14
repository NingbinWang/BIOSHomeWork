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
#include <Uefi.h>
#include "HomeWorkDxe.h"

EFI_STATUS HomeWorkHobread(
        IN  UINT8 device  
)
{
       EFI_GUID                GuidHob = HOB_LIST_GUID;
       HOMEWORK_HOB            *Homeworkhob=NULL;
       EFI_GUID                 HomeworkHobGuid=HOMEWORK_HOB_GUID;
       VOID                    *pHobList = NULL;
       EFI_STATUS              Status;
       pHobList = GetEfiConfigurationTable(pST, &GuidHob);
       if (!pHobList) return EFI_UNSUPPORTED;
           
       Homeworkhob = (HOMEWORK_HOB*)pHobList;
       while (!EFI_ERROR(Status = FindNextHobByType(EFI_HOB_TYPE_GUID_EXTENSION, &Homeworkhob)))
       {
           if (guidcmp(&(*Homeworkhob).EfiHobGuidType.Name, &HomeworkHobGuid) == 0)
                       break;
       }
       if (!EFI_ERROR(Status)){
                OEM_TRACE("device=%d,data=%d\n",device,Homeworkhob->homeworkdata);
       }
    return Status;
}

EFI_STATUS HomeWorkPciread(
           IN  UINT8 busnum,
           IN  UINT8 devicenum,
           IN  UINT8 funcnum
)
{
    OEM_TRACE("bus=%d,dev=%d,func=%d\n",busnum,devicenum,funcnum);
    return EFI_SUCCESS;
}

EFI_HOMEWORKINTERFACE_PROTOCOL  HomeworkProtocol = {
        HomeWorkHobread,
        HomeWorkPciread,  
};


VOID HomeWorkDxeProtocolCallback(
        IN EFI_EVENT                    Event,
        IN VOID                       *Context
)

{
    EFI_STATUS                             Status;
    EFI_HOMEWORKINTERFACE_PROTOCOL         *HomeworkProtocolinterface;
    Status = pBS->LocateProtocol(&gEfiHomeWorkProtocolGuid,
                                 NULL,
                                 &HomeworkProtocolinterface );
    if (!EFI_ERROR(Status)) 
    {
        Status = HomeworkProtocolinterface->HomeWorkHobread(1); 
        Status = HomeworkProtocolinterface->HomeWorkPciread(0,0,0);
    }
}



EFI_STATUS HomeWorkDxeEntryPoint(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
)
{
    
    EFI_STATUS              Status;
    EFI_EVENT              homeworkevent;
    VOID                    *Registration;

	InitAmiLib(ImageHandle,SystemTable);
	 Status = pBS->CreateEvent(
	                     EVT_NOTIFY_SIGNAL,
	                     TPL_CALLBACK,
	                     HomeWorkDxeProtocolCallback,
	                     (VOID*)NULL,
	                     &homeworkevent
	                    );
     if (EFI_ERROR(Status)) 
      {
             return Status;
      }
	 Status = pBS->RegisterProtocolNotify (
	                   &gEfiHomeWorkProtocolGuid,
	                   homeworkevent,
	                   &Registration
	                   );
	 if (EFI_ERROR(Status)) 
	 {
	         return Status;
	 }
	 Status = pBS->InstallProtocolInterface(
	                          &ImageHandle,
	                          &gEfiHomeWorkProtocolGuid,
	                          EFI_NATIVE_INTERFACE,
	                          &HomeworkProtocol
	                   );
	if (EFI_ERROR(Status)) 
	{
	     return Status;
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
