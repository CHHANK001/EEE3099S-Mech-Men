#include "Simulation3Draft_capi_host.h"
static Simulation3Draft_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Simulation3Draft_host_InitializeDataMapInfo(&(root), "Simulation3Draft");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
