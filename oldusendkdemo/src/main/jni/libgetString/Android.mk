LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := OldUseNdk
LOCAL_SRC_FILES := oldndkuse.cpp
include $(BUILD_SHARED_LIBRARY)
TARGET_ARCH_ABI := all
