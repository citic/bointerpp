#ifndef Common_h
#define Common_h

#include <cocos2d.h>

//USING_NS_CC;

#define PLATFORM_PC ((CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX))

#define PLATFORM_MOBILE ((CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8))

inline float node_width(const cocos2d::Node* node)
{
	return node->getContentSize().width;
}

inline float node_height(const cocos2d::Node* node)
{
	return node->getContentSize().height;
}

inline float half_width(const cocos2d::Node* node)
{
	return node->getContentSize().width * 0.5f;
}

inline float half_height(const cocos2d::Node* node)
{
	return node->getContentSize().height * 0.5f;
}

#define DECLARE_NO_COPY_CLASS(ClassName) \
	ClassName(const ClassName&) = delete; \
	const ClassName& operator=(const ClassName&) = delete;

// Translation to user language
#define _(STR) STR

#endif
