##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Menu
ProjectName            :=UOCJocs
ConfigurationName      :=Menu
WorkspaceConfiguration :=Menu
WorkspacePath          :=E:/temp/UOCJocs_E
ProjectPath            :=E:/temp/UOCJocs_E
IntermediateDirectory  :=./Menu
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=5/31/2023
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCJocs.txt"
PCHCompileFlags        :=
MakeDirCommand         :="C:/Program Files/CodeLite/mkdir.exe" -p
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe -r
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -Wno-unused-result -g -O2 -Wall $(Preprocessors)
CFLAGS   :=  -Wno-unused-result -g -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_purchase.c$(ObjectSuffix) $(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IntermediateDirectory)/src_store.c$(ObjectSuffix) $(IntermediateDirectory)/src_bgame.c$(ObjectSuffix) $(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IntermediateDirectory)/src_menu.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Menu"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Menu"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_purchase.c$(ObjectSuffix): src/purchase.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/purchase.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_purchase.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_purchase.c$(PreprocessSuffix): src/purchase.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_purchase.c$(PreprocessSuffix) src/purchase.c

$(IntermediateDirectory)/src_test.c$(ObjectSuffix): src/test.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_test.c$(PreprocessSuffix): src/test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_test.c$(PreprocessSuffix) src/test.c

$(IntermediateDirectory)/src_store.c$(ObjectSuffix): src/store.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/store.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_store.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_store.c$(PreprocessSuffix): src/store.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_store.c$(PreprocessSuffix) src/store.c

$(IntermediateDirectory)/src_bgame.c$(ObjectSuffix): src/bgame.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/bgame.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_bgame.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_bgame.c$(PreprocessSuffix): src/bgame.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_bgame.c$(PreprocessSuffix) src/bgame.c

$(IntermediateDirectory)/src_api.c$(ObjectSuffix): src/api.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/api.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_api.c$(PreprocessSuffix): src/api.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_api.c$(PreprocessSuffix) src/api.c

$(IntermediateDirectory)/src_menu.c$(ObjectSuffix): src/menu.c
	$(CC) $(SourceSwitch) "E:/temp/UOCJocs_E/src/menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_menu.c$(PreprocessSuffix): src/menu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_menu.c$(PreprocessSuffix) src/menu.c

##
## Clean
##
clean:
	$(RM) -r ./Menu/


