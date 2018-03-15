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
// $Header: /Alaska/Tools/template.h 6     1/13/10 2:13p Felixp $
//
// $Revision: 6 $
//
// $Date: 1/13/10 2:13p $
//**********************************************************************
// Revision History
// ----------------
// $Log: /Alaska/Tools/template.h $
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
#ifndef __HOMEWORK__H__
#define __HOMEWORK__H__

#define HOMEWORK_HOB_GUID \
{0x6ff0434a, 0x9598, 0x42cc, 0xb7, 0x38, 0xad, 0x17, 0x55, 0x48, 0x42, 0x9c}

typedef struct {
  EFI_HOB_GUID_TYPE    EfiHobGuidType; 
  UINT8    homeworkdata;  
} HOMEWORK_HOB;
#define HOMEWOORK_DEVICEID_VARIABLE_GUID  \
        {0x566d3644, 0x8590, 0x492c, 0xbe, 0x42, 0x4e, 0xf6, 0x3b, 0xa5, 0xde, 0xb7}

EFI_GUID gHomeWorkDeviceGuid = HOMEWOORK_DEVICEID_VARIABLE_GUID;

#define HOMEWOORK_VARIABLE_ATTRIBUTES \
    (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS)

#ifdef __cplusplus
extern "C" {
#endif

/****** DO NOT WRITE BELOW THIS LINE *******/
#ifdef __cplusplus
}
#endif
#endif
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
