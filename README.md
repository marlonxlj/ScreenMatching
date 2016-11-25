##iOS各种屏幕自动适配及颜色转换为十六进制


###★★★XLJMatchScreen自动适配屏幕★★★

####支持pod导入

```
pod 'XLJScreenMatching', '~> 1.1.3'

```
######如果发现pod search XLJNewFeature 搜索出来的不是最新版本，需要在终端执行cd转换文件路径命令退回到desktop，然后执行pod setup命令更新本地spec缓存（可能需要几分钟），然后再搜索就可以了。

###使用方法
直接在你的`.pch`文件中导入文件`XLJMatchScreen.h`

###更新记录:

####★★★★ 2016-11-23 ★★★★
####1. 提交iOS手写代码时对控件位置在不同的屏幕上的自动适配问题。
####2. 颜色自动转换成十六进制

####接口:

```
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


```

```
- (void)testOne
{
    
    UIView *vc = [[UIView alloc] initWithFrame:XLJ_CGRectMake(10, 80, XLJScreenWidth-20, 40)];
    
    vc.backgroundColor = [UIColor orangeColor];
    
    UILabel *lable = [[UILabel alloc] initWithFrame:XLJ_CGRectMake(10, 80, XLJScreenWidth-20, 40)];
    lable.text = @"我是测试信息:XLJ_CGRectMake";
    lable.font = [UIFont systemFontOfSize:XLJ_MatchXFlaot(14)];
    lable.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:vc];
    [self.view addSubview:lable];


}

```

###各屏幕尺寸


| 机型|屏幕尺寸 | 屏幕宽高(像素) |屏幕宽高(点) |模式 |
|---|---| ---| ---| ---|
|  iPhone 5 |  4| 640 x 1136| 320 x 568|	2x |
| iPhone 5S | 4  | 640 x 1136 | 320 x 568| 	2x |
| iPhone 6 | 4.7 | 750 x 1134 | 375 x 667 | 2x | 
| iPhone 6 Plus | 5.5 | 1080 x 1920 | 414 x 736 | 	3x |
| iPhone 6S | 4.7 | 750 x 1134 | 375 x 667 | 2x |
| iPhone 6 Plus | 5.5 | 1080 x 1920 | 414 x 736 |	3x |
| iPhone 7S | 4.7 | 750 x 1134 | 375 x 667 | 2x |
| iPhone 7 Plus | 5.5 | 1080 x 1920 | 414 x 736 |	3x |

####其实做适配，就是设计给的图是以什么为原型来设计的图片，比如以iphone5或iphone6来设计。然后再对图片进行放大或缩小的方式来匹配不同屏幕大小的iphone

####那么我们来看一下，他的一个屏幕的宽高比是怎么样的？
|机型|分辨率|宽高比|
|---|---|---|
| iphone4(s) | 960*640 | 1.5 |
| iphone5(s) | 1136*640 | 1.775|
| iphone6 | 1334*750 | 1.779 |
| iphone6Plus | 1920*1080 | 1.778|
| iphone7 | 1334*750| 1.779|
| iphone7Plus | 1920*1080 | 1.778|

####这样我就可以得出:
#####iphone5(s),iphone6P的宽高比是一至的(16:9),这样就可以进行等比缩放,按宽度进行适配。

```
/**
 XLJSrceenW  4/4s 5/5s 320  6/6s 375  6p/6sp 414 
 */
static const float XLJUISrceenWidth = 375.0;

/**
 XLJSrceenH 4/4s 修改480 5/5s 568  6/6s 667  6p/6sp 736
 */
static const float  XLJUISrceenHight =  667.0;

```
####这样得出公式:
>//按宽度适配
>
> newScreenWidth = width*(ScreenWidth/320)
> 
> //按高度适配
> newScreenHeight= height*(ScreenHeight/568)


```
在同样的逻辑分辨率下，可以通过scale参数识别是iPhone3GS还是iPhone4(s)。以下基于nativeScale参数，定义了探测机型是否为iPhone6+的宏：
--------------------------------------------------------------------------------
// not UIUserInterfaceIdiomPad
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
// detect iPhone6 Plus based on its native scale
#define IS_IPHONE_6PLUS (IS_IPHONE && [[UIScreenmainScreen] nativeScale] == 3.0f)


```

####使用宏的方式来进行适配

```
//以iphone6为基础，如果是以其它为基础设计，请自行修改既可。

```
> 
>iPhone4s屏幕的高度是480, 因此当屏幕尺寸大于iPhone4时, autoSizeScaleX和autoSizeScaleY即为当前屏幕和iPhone5尺寸的宽高比如:
如果是5，autoSizeScaleX=1，autoSizeScaleY=1；
如果是6，autoSizeScaleX=1.171875，autoSizeScaleY=1.17429577；
如果是6Plus，autoSizeScaleX=1.29375，autoSizeScaleY=1.2957；

####注:以上只是提供了实现的另一种思路，本文介绍的实现方法跟这个不一样。


####🐼🐶🐶如果对你有帮助，或觉得可以。请右上角star一下，这是对我一种鼓励，让我知道我写的东西有人认可，我才会后续不断的进行完善。

###有任何问题或建议请及时issues me，以便我能更快的进行更新修复。

####Email: marlonxlj@163.com

##PS:
![Alt Text](https://github.com/marlonxlj/ScreenMatching/blob/master/jjj.gif)
