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

#include <Library/HobLib.h>
#include <Library/BaseLib.h>
#include <Setup.h>
#include <OEMLib.h>
#include "..\HomeWork.h"
#include <Ppi/ReadOnlyVariable2.h>
#include <Library/PeimEntryPoint.h>
#include <Library/BaseMemoryLib.h>
//#include <Library/DebugLib.h>
#include <Library/PeiServicesLib.h>

EFI_STATUS HomeWorkPeimEntryPoint(
        IN       EFI_PEI_FILE_HANDLE  FileHandle,
        IN CONST EFI_PEI_SERVICES     **PeiServices
)
{
    HOMEWORK_HOB                      *homeworkhob = NULL;
    EFI_GUID                           homeworkHobGuid = HOMEWORK_HOB_GUID;
    EFI_STATUS                         Status;
    EFI_GUID                          SetupGuid = SETUP_GUID;
    EFI_PEI_READ_ONLY_VARIABLE2_PPI   *ReadOnlyVariable;
    UINTN                              VariableSize;
    SETUP_DATA                         SetupData;
    Status = PeiServicesLocatePpi(&gEfiPeiReadOnlyVariable2PpiGuid, 0, NULL, &ReadOnlyVariable);
  //  ASSERT_EFI_ERROR(Status);
    VariableSize = sizeof(SETUP_DATA);
    Status = ReadOnlyVariable->GetVariable(ReadOnlyVariable, L"Setup", &SetupGuid, NULL, &VariableSize, &SetupData);
 
    if (EFI_ERROR(Status)) {
        return Status;
    }

    Status = (*PeiServices)->CreateHob (
                               PeiServices,
                               EFI_HOB_TYPE_GUID_EXTENSION,
                               sizeof(HOMEWORK_HOB),
                               &homeworkhob);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    homeworkhob->EfiHobGuidType.Name=homeworkHobGuid;
    homeworkhob->homeworkdata=SetupData.HomeWorkoption;                 
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
