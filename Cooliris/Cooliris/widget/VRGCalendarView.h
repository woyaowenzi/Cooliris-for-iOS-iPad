//
//  VRGCalendarView.h
//  Vurig
//
//  Created by in 't Veen Tjeerd on 5/8/12.
//  Copyright (c) 2012 Vurig Media. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "UIColor+expanded.h"

#define kVRGCalendarViewTopBarHeight 60

#define kVRGCalendarViewWidth_ipad 768
#define kVRGCalendarViewWidth_iphone = 320

#define kVRGCalendarViewDayWidth_iphone = 44
#define kVRGCalendarViewDayHeight_iphone = 40

#define kVRGCalendarViewDayWidth_ipad 108
#define kVRGCalendarViewDayHeight_ipad 100

@protocol VRGCalendarViewDelegate;
@interface VRGCalendarView : UIView {
    id <VRGCalendarViewDelegate> delegate;
    
    NSDate *currentMonth;
    
    UILabel *labelCurrentMonth;
    
    BOOL isAnimating;
    BOOL prepAnimationPreviousMonth;
    BOOL prepAnimationNextMonth;
    
    UIImageView *animationView_A;
    UIImageView *animationView_B;
    
    NSArray *markedDates;
    NSArray *markedColors;
}

@property (nonatomic, retain) id <VRGCalendarViewDelegate> delegate;
@property (nonatomic, retain) NSDate *currentMonth;
@property (nonatomic, retain) UILabel *labelCurrentMonth;
@property (nonatomic, retain) UIImageView *animationView_A;
@property (nonatomic, retain) UIImageView *animationView_B;
@property (nonatomic, retain) NSArray *markedDates;
@property (nonatomic, retain) NSArray *markedColors;
@property (nonatomic, getter = calendarHeight) float calendarHeight;
@property (nonatomic, retain, getter = selectedDate) NSDate *selectedDate;
@property (nonatomic) int kVRGCalendarViewDayWidth;
@property (nonatomic) int kVRGCalendarViewDayHeight;
@property (nonatomic ) int kVRGCalendarViewWidth;

- (void)selectDate:(int)date;
- (void)reset;

- (void)markDates:(NSArray *)dates;
- (void)markDates:(NSArray *)dates withColors:(NSArray *)colors;

- (void)showNextMonth;
- (void)showPreviousMonth;

- (int)numRows;
- (void)updateSize;
- (UIImage *)drawCurrentState;
- (void)resetSizeWidth:(int)dayWidth withHeight:(int)dayHeight;

@end

@protocol VRGCalendarViewDelegate <NSObject>
- (void)calendarView:(VRGCalendarView *)calendarView switchedToMonth:(int)month targetHeight:(float)targetHeight animated:(BOOL)animated;
- (void)calendarView:(VRGCalendarView *)calendarView dateSelected:(NSDate *)date;
@end