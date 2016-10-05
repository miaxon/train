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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/rpc4stepic/Error.o \
	${OBJECTDIR}/src/rpc4stepic/net/ZMQClient.o \
	${OBJECTDIR}/src/rpc4stepic/net/ZMQServer.o \
	${OBJECTDIR}/src/rpc4stepic/net/ZMQWorker.o \
	${OBJECTDIR}/src/rpc4stepic/utils/UUID.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibrpc4stepic.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibrpc4stepic.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibrpc4stepic.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/rpc4stepic/Error.o: src/rpc4stepic/Error.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc4stepic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc4stepic/Error.o src/rpc4stepic/Error.cpp

${OBJECTDIR}/src/rpc4stepic/net/ZMQClient.o: src/rpc4stepic/net/ZMQClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc4stepic/net
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc4stepic/net/ZMQClient.o src/rpc4stepic/net/ZMQClient.cpp

${OBJECTDIR}/src/rpc4stepic/net/ZMQServer.o: src/rpc4stepic/net/ZMQServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc4stepic/net
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc4stepic/net/ZMQServer.o src/rpc4stepic/net/ZMQServer.cpp

${OBJECTDIR}/src/rpc4stepic/net/ZMQWorker.o: src/rpc4stepic/net/ZMQWorker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc4stepic/net
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc4stepic/net/ZMQWorker.o src/rpc4stepic/net/ZMQWorker.cpp

${OBJECTDIR}/src/rpc4stepic/utils/UUID.o: src/rpc4stepic/utils/UUID.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc4stepic/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc4stepic/utils/UUID.o src/rpc4stepic/utils/UUID.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibrpc4stepic.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
