##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Test
ProjectName            :=UOCJocs
ConfigurationName      :=Test
WorkspaceConfiguration :=Test
WorkspacePath          :=E:/temp/UOCJocs_E
ProjectPath            :=E:/temp/UOCJocs_E
IntermediateDirectory  :=./Test
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=5/30/2023
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=clang
SharedObjectLinkerName :=clang -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
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
AR       := ar rcus
CXX      := clang++
CC       := clang
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


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
	@$(MakeDirCommand) "./Test"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Test"

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
	$(RM) -r ./Test/


