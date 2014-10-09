LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
	../../Classes/AppDelegate.cpp \
	../../Classes/GameMenuScene.cpp \
	../../Classes/Common/GameScene.cpp \
	../../Classes/Common/BaseScene.cpp \
	../../Classes/Dialogs/InfoDialog.cpp \
	../../Classes/Dialogs/ConfigDialog.cpp \
	../../Classes/Dialogs/BaseDialog.cpp \
	../../Classes/Dialogs/PlayerDialog.cpp \
	../../Classes/Playing/UnitPlayingScene.cpp \
	../../Classes/Selection/UnitSelectionScene.cpp \


LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../Classes \
	$(LOCAL_PATH)/../../Classes/Collaboration \
	$(LOCAL_PATH)/../../Classes/Common \
	$(LOCAL_PATH)/../../Classes/Building \
	$(LOCAL_PATH)/../../Classes/Dialogs \
	$(LOCAL_PATH)/../../Classes/Playing \
	$(LOCAL_PATH)/../../Classes/Selection \


LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
