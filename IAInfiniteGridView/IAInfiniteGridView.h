//
//  IAInfiniteGridView.h
//  Infinite
//
//  Created by Ikhsan Assaat on 10/1/12.
//  Copyright (c) 2012 3kunci. All rights reserved.
//

#import <UIKit/UIKit.h>

@class IAInfiniteGridView;

@protocol IAInfiniteGridDataSource <NSObject>

- (UIView *)infiniteGridView:(IAInfiniteGridView *)gridView forIndex:(NSInteger)gridIndex;
- (NSUInteger)numberOfInfiniteGrids;
- (CGSize)infiniteGridSize;

@end

@protocol IAInfiniteGridDelegate <NSObject>

- (void)infiniteGridView:(IAInfiniteGridView *)gridView didSelectGridAtIndex:(NSInteger)gridIndex;

@end

@interface IAInfiniteGridView : UIScrollView <UIScrollViewDelegate>

@property (nonatomic, getter = isCircular) BOOL circular;
@property (nonatomic, getter = isPaging) BOOL paging;
@property (nonatomic, assign) IBOutlet id<IAInfiniteGridDataSource> dataSource;
@property (nonatomic, assign) IBOutlet id<IAInfiniteGridDelegate> gridDelegate;

- (id)dequeueReusableGrid;
- (void)jumpToIndex:(NSInteger)gridIndex;
- (UIView *)gridViewAtPoint:(CGPoint)point;

@end
