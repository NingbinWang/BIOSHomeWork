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
#ifndef __HOMEWORKDXE__H__
#define __HOMEWORKDXE__H__

extern EFI_GUID gEfiHomeWorkProtocolGuid;
typedef EFI_STATUS (* HOMEWORK_HOB_READ) (
    IN  UINT8 device
   
);

typedef EFI_STATUS (* HOMEWORK_PCI_READ) (
    IN  UINT8 busnum,
    IN  UINT8 devicenum,
    IN  UINT8 funcnum
);

struct _EFI_HOMEWORK_PROTOCOL{
    HOMEWORK_HOB_READ HomeWorkHobread;
    HOMEWORK_PCI_READ HomeWorkPciread;
};

typedef struct _EFI_HOMEWORK_PROTOCOL  EFI_HOMEWORKINTERFACE_PROTOCOL;
        // {47590bea-6178-498d-a905-3ce663c384d9} 
#define EFI_HOMEWORKINTERFACE_PROTOCOL_GUID \
          { \
            0x47590bea, 0x6178, 0x498d, {0xa9, 0x5, 0x3c, 0xe6, 0x63, 0xc3, 0x84, 0xd9} \
          }
EFI_GUID gEfiHomeWorkProtocolGuid = EFI_HOMEWORKINTERFACE_PROTOCOL_GUID;
#pragma pack()        
        
        
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
