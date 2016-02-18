#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Experiment.o \
	${OBJECTDIR}/Tensor/HVolume.o \
	${OBJECTDIR}/Tensor/Matrix.o \
	${OBJECTDIR}/Tensor/Vector.o \
	${OBJECTDIR}/Tensor/Volume.o \
	${OBJECTDIR}/app.o \
	${OBJECTDIR}/layerdefs/ConvLayer.o \
	${OBJECTDIR}/layerdefs/FCLayer.o \
	${OBJECTDIR}/layerdefs/PoolLayer.o \
	${OBJECTDIR}/netdef/ConvNet.o \
	${OBJECTDIR}/utility/operations.o \
	${OBJECTDIR}/utility/readpics.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-static-libgcc -static-libstdc++
CXXFLAGS=-static-libgcc -static-libstdc++

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bettercnn

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bettercnn: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bettercnn ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Experiment.o: Experiment.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Experiment.o Experiment.cpp

${OBJECTDIR}/Tensor/HVolume.o: Tensor/HVolume.cpp 
	${MKDIR} -p ${OBJECTDIR}/Tensor
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tensor/HVolume.o Tensor/HVolume.cpp

${OBJECTDIR}/Tensor/Matrix.o: Tensor/Matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/Tensor
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tensor/Matrix.o Tensor/Matrix.cpp

${OBJECTDIR}/Tensor/Vector.o: Tensor/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/Tensor
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tensor/Vector.o Tensor/Vector.cpp

${OBJECTDIR}/Tensor/Volume.o: Tensor/Volume.cpp 
	${MKDIR} -p ${OBJECTDIR}/Tensor
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tensor/Volume.o Tensor/Volume.cpp

${OBJECTDIR}/app.o: app.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/app.o app.cpp

${OBJECTDIR}/layerdefs/ConvLayer.o: layerdefs/ConvLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/layerdefs
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/layerdefs/ConvLayer.o layerdefs/ConvLayer.cpp

${OBJECTDIR}/layerdefs/FCLayer.o: layerdefs/FCLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/layerdefs
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/layerdefs/FCLayer.o layerdefs/FCLayer.cpp

${OBJECTDIR}/layerdefs/PoolLayer.o: layerdefs/PoolLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/layerdefs
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/layerdefs/PoolLayer.o layerdefs/PoolLayer.cpp

${OBJECTDIR}/netdef/ConvNet.o: netdef/ConvNet.cpp 
	${MKDIR} -p ${OBJECTDIR}/netdef
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/netdef/ConvNet.o netdef/ConvNet.cpp

${OBJECTDIR}/utility/operations.o: utility/operations.cpp 
	${MKDIR} -p ${OBJECTDIR}/utility
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utility/operations.o utility/operations.cpp

${OBJECTDIR}/utility/readpics.o: utility/readpics.cpp 
	${MKDIR} -p ${OBJECTDIR}/utility
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utility/readpics.o utility/readpics.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bettercnn

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
