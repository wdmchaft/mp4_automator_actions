/*
 *  Edit MPEG-4 Metadata Tags.h
 *
 *  Copyright (C) 2011 Brian D. Wells
 *
 *  This file is part of MP4 Automator Actions.
 *
 *  MP4 Automator Actions is free software: you can redistribute it 
 *  and/or modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation, either version 3 of
 *  the License, or (at your option) any later version.
 *
 *  MP4 Automator Actions is distributed in the hope that it will be 
 *  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with MP4 Automator Actions.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permission under GNU GPL version 3 section 7
 *
 *  If you modify MP4 Automator Actions, or any covered work, by linking 
 *  or combining it with MP4v2 (or a modified version of that library), 
 *  containing parts covered by the terms of Mozilla Public License 1.1, 
 *  the licensors of MP4 Automator Actions grant you additional permission 
 *  to convey the resulting work. Corresponding Source for a non-source 
 *  form of such a combination shall include the source code for the parts 
 *  of MP4v2 used as well as that of the covered work.
 *
 *  Author: Brian D. Wells <spam_brian@me.com>
 *  Website: https://github.com/brianwells/mp4_automator_actions
 *
 */

#import <Cocoa/Cocoa.h>
#import <Automator/AMBundleAction.h>
#import <Quartz/Quartz.h>
#include <dispatch/dispatch.h>
#include <mp4v2/mp4v2.h>
#import "ImageDataTransformer.h"
#import "ImagesArrayController.h"
#import "TextSnippet.h"
#import "TokenStringTransformer.h"

// indicate that AMBundleAction implements NSTokenFieldDelegate protocol
@interface AMBundleAction (TokenFields) <NSTokenFieldDelegate>
@end

@interface Edit_MPEG_4_Metadata_Tags : AMBundleAction < NSTokenFieldDelegate >
{
	IBOutlet NSWindow *tagsWindow;
    IBOutlet NSArrayController *genreController;
    IBOutlet NSArrayController *mediaKindController;
    IBOutlet NSArrayController *contentRatingController;
    IBOutlet NSArrayController *snippetsController;
    IBOutlet ImagesArrayController *imagesController;
    IBOutlet NSArrayController *filesController;
	IBOutlet IKImageBrowserView *artworkBrowser;
	IBOutlet NSTextView *lyricsView;
	IBOutlet NSTabView *tabView;
	IBOutlet NSTokenField *snippetTokenField;
    IBOutlet NSTextField *snippetLabel;
	NSMutableDictionary *results;
	NSMutableArray *artworkImages;
    NSManagedObjectContext *managedObjectContext;
    NSPersistentStoreCoordinator *persistentStoreCoordinator;
    NSNumber *imageZoom;
	NSArray *genreList;
	NSArray *kindList;
	NSArray *ratingList;
    BOOL snippetsConfigured;
	NSArray *oldSnippets;
}

@property (copy) NSNumber *imageZoom;
@property (copy) NSArray *oldSnippets;

- (NSManagedObjectModel *)managedObjectModel;
- (NSManagedObjectContext *)managedObjectContext;
- (NSPersistentStoreCoordinator *)persistentStoreCoordinator;
- (NSArray *)filesSortDescriptors;
- (NSArray *)imagesSortDescriptors;

- (void)runAsynchronouslyWithInput:(id)input;
- (void)willFinishRunning;
- (id)output;

- (IBAction)saveAction:(id)sender;
- (IBAction)cancelAction:(id)sender;
- (IBAction)addArtworkImage:(id)sender;
- (IBAction)removeArtworkImage:(id)sender;
- (IBAction)addSnippet:(id)sender;

- (void)updateSnippetsParameter;

@end
