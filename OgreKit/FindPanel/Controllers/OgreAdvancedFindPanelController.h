/*
 * Name: OgreAdvancedFindPanelController.h
 * Project: OgreKit
 *
 * Creation Date: Sep 14 2003
 * Author: Isao Sonobe <sonobe@gauge.scphys.kyoto-u.ac.jp>
 * Copyright: Copyright (c) 2003 Isao Sonobe, All rights reserved.
 * License: OgreKit License
 *
 * Encoding: UTF8
 * Tabsize: 4
 */

#import <Cocoa/Cocoa.h>
#import <OgreKit/OgreTextFinder.h>
#import <OgreKit/OgreFindPanelController.h>
#import <OgreKit/OgreTextFindThread.h>

@class OgreAFPCEscapeCharacterFormatter, OgreFindResultWindowController;

@interface OgreAdvancedFindPanelController : OgreFindPanelController 
{
    IBOutlet NSPopUpButton	*escapeCharacterPopUpButton;
    IBOutlet NSComboBox		*findComboBox;
	NSComboBoxCell			*_findComboBoxCell;
    IBOutlet NSColorWell	*highlightColorWell;
    IBOutlet NSDrawer		*moreOptionsDrawer;
    IBOutlet NSMatrix		*moreOptionsMatrix;
    IBOutlet NSButtonCell	*optionDelimitCheckBox;
    IBOutlet NSButtonCell	*optionIgnoreCaseCheckBox;
    IBOutlet NSButtonCell	*optionWrapCheckBox;
    IBOutlet NSButtonCell	*optionRegexCheckBox;
    IBOutlet NSMatrix		*originMatrix;
    IBOutlet NSComboBox		*replaceComboBox;
	NSComboBoxCell			*_replaceComboBoxCell;
    IBOutlet NSMatrix		*scopeMatrix;
	
    IBOutlet NSButton		*closeWhenDoneCheckBox;
    IBOutlet NSTextField	*maxNumOfFindHistoryTextField;
    IBOutlet NSTextField	*maxNumOfReplaceHistoryTextField;
    IBOutlet NSPopUpButton	*syntaxPopUpButton;

	NSMutableArray			*_findHistory;
	NSMutableArray			*_replaceHistory;
	int						_delimitChackBoxState;
	BOOL					_isAlertSheetOpen;
	
	OgreAFPCEscapeCharacterFormatter  *_escapeCharacterFormatter;
	
	IBOutlet NSButton		*findNextButton;
	IBOutlet NSButton		*moreOptionsButton;
    
	OgreFindResultWindowController    *_findResultWindowController;
	
    BOOL                    _altKeyDown;
    BOOL                    _tmpIsEntire;
}

/* find/replace/highlight actions */
- (IBAction)findAll:(id)sender;

- (IBAction)findNext:(id)sender;
- (IBAction)findNextAndOrderOut:(id)sender;
- (OgreTextFindResult*)findNextStrategy;

- (IBAction)findPrevious:(id)sender;
- (IBAction)findSelectedText:(id)sender;
- (IBAction)highlight:(id)sender;
- (IBAction)jumpToSelection:(id)sender;
- (IBAction)replace:(id)sender;
- (IBAction)replaceAll:(id)sender;
- (IBAction)replaceAndFind:(id)sender;
- (IBAction)unhighlight:(id)sender;
- (IBAction)useSelectionForFind:(id)sender;
- (IBAction)useSelectionForReplace:(id)sender;

/* update settings */
- (IBAction)updateEscapeCharacter:(id)sender;
- (IBAction)updateOptions:(id)sender;
- (IBAction)updateSyntax:(id)sender;
- (void)enableDelimitCheckBox:(BOOL)changeToEnable;
- (void)avoidEmptySelection;
- (void)setStartFromCursor;
- (void)setIsEntire:(BOOL)isEntire;

/* delegate methods of OgreAdvancedFindPanel */
- (void)findPanelFlagsChanged:(unsigned)modifierFlags;
- (void)findPanelDidAddChildWindow:(NSWindow*)childWindow;
- (void)findPanelDidRemoveChildWindow:(NSWindow*)childWindow;

/* settings */
- (NSString*)escapeCharacter;
- (BOOL)shouldEquateYenWithBackslash;
- (BOOL)isEntire;
- (BOOL)isStartFromTop;
- (BOOL)isWrap;
- (unsigned)options;
- (OgreSyntax)syntax;

/* find/replace history */
- (void)addFindHistory:(NSString*)string;
- (void)addReplaceHistory:(NSString*)string;
- (IBAction)clearFindReplaceHistories:(id)sender;

/* restore history/settings */
- (void)restoreHistory:(NSDictionary*)history;

/* show alert */
- (BOOL)alertIfInvalidRegex;
- (void)showErrorAlert:(NSString*)title message:(NSString*)message;

/* load find string to/from pasteboard */
- (void)loadFindStringFromPasteboard;
- (void)loadFindStringToPasteboard;

@end