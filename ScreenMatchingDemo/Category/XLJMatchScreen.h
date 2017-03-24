//
//  XLJMatchScreen.h
//  ScreenMatchingDemo
//
//  Created by marlonxlj on 2016/11/22.
//  Copyright © 2016年 XLJ. All rights reserved.
//  Email:marlonxlj@163.com
//
//  在项目中经常遇到一些手写的代码，及时使用了Masonry进行约束，但还是有的控件的位置不正确。使用这个可以不用担心UI设计是以iphone5s为基础原型设计的，还是以iphone6为基础原型设计,都可以做到完美的适配。在使用中如遇到问题请及时联系我，以便立即做出修改。
//

#ifndef XLJMatchScreen_h
#define XLJMatchScreen_h

/**
 *  颜色定义
 *  实现颜色转换为十六进制
 */
//转换后是否带透明度
#define XLJUIColorFromHexValueWihtAlpha(hexValue,alphaValue) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:alphaValue]
//转换后不带透明度
#define XLJUIColorFromHexValue(hexValue) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:1.0]

#define XLJColorWithRGBA(R/*红*/, G/*绿*/, B/*蓝*/, A/*透明*/) \
[UIColor colorWithRed:R/255.f green:G/255.f blue:B/255.f alpha:A]

/** 屏幕宽度*/
#define XLJScreenWidth CGRectGetWidth([UIScreen mainScreen].bounds)
/** 屏幕高度 */
#define XLJScreenHight CGRectGetHeight([UIScreen mainScreen].bounds)

/**
 * 不同机型的宽度  4/4s 5/5s 320  6/6s/7 375  6p/6sp/7p 414
 *
 *
 * 不同机型的高度 4/4s 480 5/5s 568  6/6s/7 667  6p/6sp/7p 736
 */
//屏幕缩放比例
static float  XLJAutoSizeScaleX = 0;
static float  XLJAutoSizeScaleY = 0;

/**X的适配*/
CG_INLINE CGFloat XLJ_MatchXFlaot(CGFloat X){
    
    if (XLJScreenHight > 568) {
        XLJAutoSizeScaleX = 1.0;
        return X *XLJAutoSizeScaleX;
    }else if (XLJScreenHight > 667){
        XLJAutoSizeScaleX = XLJScreenWidth/414;
        return X * XLJAutoSizeScaleX;
    }else{
        XLJAutoSizeScaleX = 1.0;
        return X * XLJAutoSizeScaleX;
    }
}

/**Y的适配*/
CG_INLINE CGFloat XLJ_MatchYFlaot(CGFloat Y){
    
    if (XLJScreenHight > 568) {
        XLJAutoSizeScaleY = 1.0;
        return Y *XLJAutoSizeScaleX;
    }else if (XLJScreenHight > 667){
        XLJAutoSizeScaleY = XLJScreenHight/736;
        return Y * XLJAutoSizeScaleY;
    }else{
        XLJAutoSizeScaleY = 1.0;
        return Y * XLJAutoSizeScaleY;
    }
    
}

/**适配Width*/
CG_INLINE CGFloat XLJ_MatchWidthFlaot(CGFloat width) {
    
    if (XLJScreenHight > 568) {
        XLJAutoSizeScaleX = 1.0;
        return width *XLJAutoSizeScaleX;
    }else if (XLJScreenHight > 667){
        XLJAutoSizeScaleX = XLJScreenWidth/414;
        return width * XLJAutoSizeScaleX;
    }else{
        XLJAutoSizeScaleX = 1.0;
        return width * XLJAutoSizeScaleX;
    }
    
}

/**适配Height*/
CG_INLINE CGFloat XLJ_MathHeightFlaot(CGFloat height) {
    
    if (XLJScreenHight > 568) {
        XLJAutoSizeScaleY = 1.0;
        return height *XLJAutoSizeScaleX;
    }else if (XLJScreenHight > 667){
        XLJAutoSizeScaleY = XLJScreenHight/736;
        return height * XLJAutoSizeScaleY;
    }else{
        XLJAutoSizeScaleY = 1.0;
        return height * XLJAutoSizeScaleY;
    }
    
}

/**
 * 重写RectMake
 */
CG_INLINE CGRect
XLJ_CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
    CGRect rect;
    rect.origin.x = XLJ_MatchXFlaot(x);
    rect.origin.y = XLJ_MatchYFlaot(y);
    rect.size.width = XLJ_MatchWidthFlaot(width);
    rect.size.height = XLJ_MathHeightFlaot(height);
    
    return rect;
}

/**
 * 重写CGPoint
 */
CG_INLINE CGPoint
XLJ_CGPointMake(CGFloat X, CGFloat Y)
{
    CGPoint point;
    if (XLJScreenHight > 568) {
        XLJAutoSizeScaleY = 1.0;
        XLJAutoSizeScaleY = 1.0;
        point.x = X * XLJAutoSizeScaleX;
        point.y = Y * XLJAutoSizeScaleY;
        return point;
    }else if (XLJScreenHight > 667){
        XLJAutoSizeScaleX = XLJScreenWidth/414;
        XLJAutoSizeScaleY = XLJScreenHight/736;
        point.x = X *XLJAutoSizeScaleX;
        point.y = Y *XLJAutoSizeScaleY;
        return point;
    }else{
        XLJAutoSizeScaleY = 1.0;
        XLJAutoSizeScaleY = 1.0;
        point.x = X * XLJAutoSizeScaleX;
        point.y = Y * XLJAutoSizeScaleY;
        return point;
    }
    
}

/**
 * 重写CGSize
 */
CG_INLINE CGSize
XLJ_CGSizeMake(CGFloat Width, CGFloat Height)
{
    CGSize size;
    if (XLJScreenHight > 568) {
        XLJAutoSizeScaleY = 1.0;
        XLJAutoSizeScaleY = 1.0;
        size.width = Width * XLJAutoSizeScaleX;
        size.height = Height * XLJAutoSizeScaleY;
        return size;
    }else if (XLJScreenHight > 667){
        XLJAutoSizeScaleX = XLJScreenWidth/414;
        XLJAutoSizeScaleY = XLJScreenHight/736;
        size.width = Width *XLJAutoSizeScaleX;
        size.height = Width *XLJAutoSizeScaleY;
        return size;
    }else{
        XLJAutoSizeScaleY = 1.0;
        XLJAutoSizeScaleY = 1.0;
        size.width = Width * XLJAutoSizeScaleX;
        size.height = Height * XLJAutoSizeScaleY;
        return size;
    }
    
}

//自定义字体
//#define XLJ_FontSize(fontSize) [UIFont fontWithName:@"HiraginoSans-W3" size:fontSize]

//字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )

//数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)

//字典是否为空
#define kDictIsEmpty(dic) (dic.count == 0 || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)

//是否是空对象
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))



#endif /* XLJMatchScreen_h */
