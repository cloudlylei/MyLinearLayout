//
//  MyGridNode.h
//  MyLayout
//
//  Created by oubaiquan on 2017/8/24.
//  Copyright © 2017年 YoungSoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyGrid.h"


//子栅格类型。
typedef enum : unsigned char {
    MySubGridsType_Unknown,
    MySubGridsType_Row,
    MySubGridsType_Col,
} MySubGridsType;


@protocol MyGridNode<MyGrid>

@property(nonatomic, weak) id<MyGridNode> superGrid;

//子栅格数组
@property(nonatomic, strong) NSMutableArray<id<MyGridNode>> *subGrids;

//子栅格类型
@property(nonatomic, assign) MySubGridsType subGridsType;


//栅格的尺寸
@property(nonatomic, assign) CGFloat gridMeasure;

//栅格的rect
@property(nonatomic) CGRect gridRect;


//得到栅格布局视图
-(UIView*)gridLayoutView;

//更新栅格尺寸。返回对应方向的尺寸
-(CGFloat)updateGridSize:(CGSize)superSize superGrid:(id<MyGridNode>)superGrid withMeasure:(CGFloat)measure;

//更新栅格位置。返回对应方向的尺寸
-(CGFloat)updateGridOrigin:(CGPoint)superOrigin superGrid:(id<MyGridNode>)superGrid withOffset:(CGFloat)offset;


//栅格边界线的支持。
-(void)setBorderlineNeedLayoutIn:(CGRect)rect withLayer:(CALayer*)layer;
-(void)showBorderline:(BOOL)show;


//栅格触摸事件的支持。

//栅格点击测试，返回最佳的响应事件的子栅格或者自己。
-(id<MyGridNode>)gridhitTest:(CGPoint *)pt;

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;


@end


//普通节点。
@interface MyGridNode : NSObject<MyGridNode>


-(instancetype)initWithMeasure:(CGFloat)measure superGrid:(id<MyGridNode>)superGrid;


@property(nonatomic)    NSInteger tag;


@property(nonatomic, weak) id<MyGridNode> superGrid;

//子栅格是否列栅格
@property(nonatomic, strong) NSMutableArray<id<MyGridNode>> *subGrids;
@property(nonatomic, assign) MySubGridsType subGridsType;


//格子内子栅格的间距
@property(nonatomic, assign) CGFloat subviewSpace;

//格子内视图的内边距。
@property(nonatomic, assign) UIEdgeInsets padding;

//格子内子视图的对齐停靠方式。
@property(nonatomic, assign) MyGravity gravity;

//是否占位标志。
@property(nonatomic, assign) BOOL placeholder;


@property(nonatomic, assign) CGFloat gridMeasure;
@property(nonatomic) CGRect gridRect;


@property(nonatomic, strong) NSDictionary* gridDictionary;

@end






