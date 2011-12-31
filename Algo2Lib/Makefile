SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = Algo2

#--- Inputs ----#
UNITY_HOME = unity
CPP_PLATFORM = gcc
PROJECT_HOME_DIR = .
PROJECT_TEST_DIR = test
UNITY_BUILD_HOME = unity/extras/fixture/build

UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar
UNITY_WARNINGFLAGS = -Wall -Werror -Wswitch-default
#UNITY_WARNINGFLAGS += -Wshadow 

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src \

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR)\
	$(UNITY_HOME)/src\
    $(UNITY_HOME)/extras/fixture/src\
    $(UNITY_HOME)/extras/fixture/test\

INCLUDE_DIRS =\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/extras/fixture/src\
  $(UNITY_HOME)/extras/fixture/test\
  $(PROJECT_HOME_DIR)/include\
  
include $(UNITY_BUILD_HOME)/MakefileWorker.mk

