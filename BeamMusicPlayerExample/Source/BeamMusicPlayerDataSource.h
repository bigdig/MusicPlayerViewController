//
//  BeamMusicPlayerDataSource.h
//  BeamMusicPlayerExample
//
//  Created by Moritz Haarmann on 30.05.12.
//  Copyright (c) 2012 n/a. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Block Type used to receive images from the BeamMusicPlayerDataSource
 */
typedef void(^BeamMusicPlayerReceivingBlock)(UIImage* image, NSError** error);


@class BeamMusicPlayerViewController;

/**
 * The DataSource for the Music Player provides all data necessary to display
 * a player UI filled with the appropriate information. 
 */
@protocol BeamMusicPlayerDataSource <NSObject>

/**
 * Returns the title of the given track and player as a NSString. You can return nil for no title.
 */
-(NSString*)musicPlayer:(BeamMusicPlayerViewController*)player titleForTrack:(NSUInteger)trackNumber;

/**
 * Returns the artist for the given track in the given player. Nil is an acceptable return value.
 */
-(NSString*)musicPlayer:(BeamMusicPlayerViewController*)player artistForTrack:(NSUInteger)trackNumber;

/**
* Returns the album for the given track in the given player. Nil is an acceptable return value.
*/
-(NSString*)musicPlayer:(BeamMusicPlayerViewController*)player albumForTrack:(NSUInteger)trackNumber;

/**
 * Returns the length for the given track in the given player as seconds. Your implementation must provide a 
 * value larger than 0.
 */
-(CGFloat)musicPlayer:(BeamMusicPlayerViewController*)player lengthForTrack:(NSUInteger)trackNumber;

@optional

/**
 * Returns the number of tracks for the given player. If you do not implement this method
 * or return anything smaller than 2, one track is assumed and the skip-buttons are disabled.
 */
-(NSUInteger)numberOfTracksInPlayer:(BeamMusicPlayerViewController*)player;


-(void)musicPlayer:(BeamMusicPlayerViewController*)player artworkForTrack:(NSUInteger)trackNumber receivingBlock:(BeamMusicPlayerReceivingBlock)receivingBlock;

@end
