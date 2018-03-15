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

//**********************************************************************
// $Header: /Alaska/Tools/template.c 6     1/13/10 2:13p Felixp $
//
// $Revision: 6 $
//
// $Date: 1/13/10 2:13p $
//**********************************************************************
// Revision History
// ----------------
// $Log: /Alaska/Tools/template.c $
// 
// 6     1/13/10 2:13p Felixp
// 
//**********************************************************************
//<AMI_FHDR_START>
//
// Name:  <This File's Name>
//
// Description:	
//
//<AMI_FHDR_END>
//**********************************************************************
#include "HomeWork.h"
#include <Setup.h>
#include <Uefi.h>
#include <AmiLib.h>
#include <AmiDxeLib.h>
#include <Library/HiiLib.h>
//#include <OEMLib.h>
VOID
InitHomeWorkStrings (
  EFI_HII_HANDLE HiiHandle,
  UINT16         Class
  )
{      
       UINT16              Value;
       UINTN               ValueSize;
       EFI_STATUS              Status;
       Status = pRS->GetVariable(L"Homeworkdeviceid",
           &gHomeWorkDeviceGuid,
           NULL,
           &ValueSize,
           &Value);
   //    OEM_TRACE("InitHomeWorkStrings=%x\n",Value);
       if (!EFI_ERROR(Status)) {
           InitString(HiiHandle, STRING_TOKEN(STR_HOMEWORK_TEXT_VALUE), L"%x",Value);  
       }
    
   
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
