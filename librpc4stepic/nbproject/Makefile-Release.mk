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
	${OBJECTDIR}/src/net/ZMQClient.o \
	${OBJECTDIR}/src/rpc/RPCFileSystem.o \
	${OBJECTDIR}/src/rpc/RPCObject.o \
	${OBJECTDIR}/src/serialize/Packer.o \
	${OBJECTDIR}/src/serialize/Request.o \
	${OBJECTDIR}/src/serialize/Responce.o


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

${OBJECTDIR}/src/net/ZMQClient.o: src/net/ZMQClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/net
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/net/ZMQClient.o src/net/ZMQClient.cpp

${OBJECTDIR}/src/rpc/RPCFileSystem.o: src/rpc/RPCFileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc/RPCFileSystem.o src/rpc/RPCFileSystem.cpp

${OBJECTDIR}/src/rpc/RPCObject.o: src/rpc/RPCObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rpc
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rpc/RPCObject.o src/rpc/RPCObject.cpp

${OBJECTDIR}/src/serialize/Packer.o: src/serialize/Packer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/serialize
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/serialize/Packer.o src/serialize/Packer.cpp

${OBJECTDIR}/src/serialize/Request.o: src/serialize/Request.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/serialize
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/serialize/Request.o src/serialize/Request.cpp

${OBJECTDIR}/src/serialize/Responce.o: src/serialize/Responce.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/serialize
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/serialize/Responce.o src/serialize/Responce.cpp

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
