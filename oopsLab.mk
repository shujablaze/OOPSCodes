##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=oopsLab
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=D:/oopsLab/oopsLab
ProjectPath            :=D:/oopsLab/oopsLab/oopsLab
IntermediateDirectory  :=../build-$(ConfigurationName)/oopsLab
OutDir                 :=../build-$(ConfigurationName)/oopsLab
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Shuja
Date                   :=16/12/2021
CodeLitePath           :="d:/Program Files/CodeLite"
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
CXXFLAGS :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=d:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/oopsLab/1.cpp$(ObjectSuffix) 



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
../build-$(ConfigurationName)/oopsLab/1.cpp$(ObjectSuffix): 1.cpp ../build-$(ConfigurationName)/oopsLab/1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/oopsLab/oopsLab/oopsLab/1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/1.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/oopsLab/1.cpp$(DependSuffix): 1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/oopsLab/1.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/oopsLab/1.cpp$(DependSuffix) -MM 1.cpp

../build-$(ConfigurationName)/oopsLab/1.cpp$(PreprocessSuffix): 1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/oopsLab/1.cpp$(PreprocessSuffix) 1.cpp


-include ../build-$(ConfigurationName)/oopsLab//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


