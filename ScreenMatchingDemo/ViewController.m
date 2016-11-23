//
//  ViewController.m
//  ScreenMatchingDemo
//
//  Created by m on 2016/11/18.
//  Copyright © 2016年 XLJ. All rights reserved.
//

#import "ViewController.h"
#import "XLJMatchScreen.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];


    //1.测试基础属性:XLJ_CGRectMake
    [self testOne];
    
    //1.2测试颜色
    [self testTwo];
    
    //1.2测试CGPoint
    
}

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

- (void)testTwo
{
    
    UIView *vc = [[UIView alloc] initWithFrame:XLJ_CGRectMake(0, 0, 40, 40)];
    
    vc.center = XLJ_CGPointMake(XLJScreenWidth/2.0, XLJScreenHight/2.0);
    vc.backgroundColor = XLJUIColorFromHexValue(0x7FFF00);
    
    [self.view addSubview:vc];
}





@end
