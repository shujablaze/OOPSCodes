##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=oopsLab
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=E:/oopsLab/oopsLab
ProjectPath            :=E:/oopsLab/oopsLab/oopsLab
IntermediateDirectory  :=../build-$(ConfigurationName)/oopsLab
OutDir                 :=../build-$(ConfigurationName)/oopsLab
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=shuja
Date                   :=07/09/2021
CodeLitePath           :="E:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/oopsLab/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\oopsLab" mkdir "..\build-$(ConfigurationName)\oopsLab"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\oopsLab" mkdir "..\build-$(ConfigurationName)\oopsLab"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/oopsLab/.d:
	@if not exist "..\build-$(ConfigurationName)\oopsLab" mkdir "..\build-$(ConfigurationName)\oopsLab"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(ObjectSuffix): RectangleLab5.cpp ../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oopsLab/oopsLab/oopsLab/RectangleLab5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RectangleLab5.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(DependSuffix): RectangleLab5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(DependSuffix) -MM RectangleLab5.cpp

../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(PreprocessSuffix): RectangleLab5.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/oopsLab/RectangleLab5.cpp$(PreprocessSuffix) RectangleLab5.cpp


-include ../build-$(ConfigurationName)/oopsLab//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


