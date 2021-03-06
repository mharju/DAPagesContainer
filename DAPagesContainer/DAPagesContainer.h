//
//  DAPageContainerScrollView.h
//  DAPagesContainerScrollView
//
//  Created by Daria Kopaliani on 5/29/13.
//  Copyright (c) 2013 Daria Kopaliani. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface DAPagesContainer : UIViewController

/**
 The view controllers to be displayed in DAPagesContainer in order they appear in this array.
 @discussion view objects for all the view controllers will be resized to fit the container bounds together with topBar. Normally you should have more than one view controller.
 @warning all view controllers should have nonempty titles which are displayed in the top bar.
 */
@property (strong, nonatomic) NSArray *viewControllers;

/**
 An index of the selected view controller.
 */
@property (assign, nonatomic) NSUInteger selectedIndex;

/**
 A hight of the top bar. Every time this value is changed, view objects for all the view controllers are resized.
 This is 44. by default.
 */
@property (assign, nonatomic) NSUInteger topBarHeight;

/**
 A size of the page indicator view.
 This is {17., 7.} by default.
 */
@property (assign, nonatomic) CGSize pageIndicatorViewSize;

/**
 A background color of the top bar.
 This is black by default.
 */
@property (strong, nonatomic) UIColor *topBarBackgroundColor;

/**
 A font for all the buttons displayed in the top bar.
 This is system font of sixe 12. by default.
 */
@property (strong, nonatomic) UIFont *topBarItemLabelsFont;

/**
 A color of all the view titles displayed on the top bar except for the selected one.
 This is light gray by default.
 */
@property (strong, nonatomic) UIColor *pageItemsTitleColor;

/**
 A color of the selected view titles displayed on the top bar.
 This is white by default.
 */
@property (strong, nonatomic) UIColor *selectedPageItemTitleColor;

@property (strong, nonatomic) UIColor *selectedPageItemBackgroundColor;

@property (strong, nonatomic) void (^selectedIndexChangedBlock)(NSInteger previous, NSInteger current);

- (void) topBarShadow:(UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius opacity:(CGFloat)opacity;
                                                                                            
/**
 Changes 'selectedIndex' property value and navigates to the newly selected view controller
 @param selectedIndex This mathod throws exeption if selectedIndex is out of range of the 'viewControllers' array
 @param animated Defines whether to present the corresponding view controller animated
 @discussion If 'animated' is YES and the newly selected view is not "the closest neighbor" of the previous selected view, all the intermediate views will be skipped for the sake of nice animation
 */
- (void)setSelectedIndex:(NSUInteger)selectedIndex animated:(BOOL)animated;

/**
 Makes sure that view objects for all the view controllers are properly resized to fit the container bounds after device orientation was changed
 */
- (void)updateLayoutForNewOrientation:(UIInterfaceOrientation)orientation;

- (void) updateHeight:(CGFloat)newHeight;

@end