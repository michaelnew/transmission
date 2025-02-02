/******************************************************************************
 * Copyright (c) 2005-2019 Transmission authors and contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>

#include <libtransmission/transmission.h>

@class PortChecker;

@interface PrefsController : NSWindowController<NSToolbarDelegate>
{
    tr_session* fHandle;
    NSUserDefaults* fDefaults;
    BOOL fHasLoaded;

    IBOutlet NSView* fGeneralView;
    IBOutlet NSView* fTransfersView;
    IBOutlet NSView* fBandwidthView;
    IBOutlet NSView* fPeersView;
    IBOutlet NSView* fNetworkView;
    IBOutlet NSView* fRemoteView;
    IBOutlet NSView* fGroupsView;

    NSString* fInitialString;

    IBOutlet NSButton* fSystemPreferencesButton;
    IBOutlet NSTextField* fCheckForUpdatesLabel;
    IBOutlet NSButton* fCheckForUpdatesButton;
    IBOutlet NSButton* fCheckForUpdatesBetaButton;

    IBOutlet NSPopUpButton* fFolderPopUp;
    IBOutlet NSPopUpButton* fIncompleteFolderPopUp;
    IBOutlet NSPopUpButton* fImportFolderPopUp;
    IBOutlet NSPopUpButton* fDoneScriptPopUp;
    IBOutlet NSButton* fShowMagnetAddWindowCheck;
    IBOutlet NSTextField* fRatioStopField;
    IBOutlet NSTextField* fIdleStopField;
    IBOutlet NSTextField* fQueueDownloadField;
    IBOutlet NSTextField* fQueueSeedField;
    IBOutlet NSTextField* fStalledField;

    IBOutlet NSTextField* fUploadField;
    IBOutlet NSTextField* fDownloadField;
    IBOutlet NSTextField* fSpeedLimitUploadField;
    IBOutlet NSTextField* fSpeedLimitDownloadField;
    IBOutlet NSPopUpButton* fAutoSpeedDayTypePopUp;

    IBOutlet NSTextField* fPeersGlobalField;
    IBOutlet NSTextField* fPeersTorrentField;
    IBOutlet NSTextField* fBlocklistURLField;
    IBOutlet NSTextField* fBlocklistMessageField;
    IBOutlet NSTextField* fBlocklistDateField;
    IBOutlet NSButton* fBlocklistButton;

    PortChecker* fPortChecker;
    IBOutlet NSTextField* fPortField;
    IBOutlet NSTextField* fPortStatusField;
    IBOutlet NSButton* fNatCheck;
    IBOutlet NSImageView* fPortStatusImage;
    IBOutlet NSProgressIndicator* fPortStatusProgress;
    NSTimer* fPortStatusTimer;
    int fPeerPort, fNatStatus;

    IBOutlet NSTextField* fRPCPortField;
    IBOutlet NSTextField* fRPCPasswordField;
    IBOutlet NSTableView* fRPCWhitelistTable;
    NSMutableArray* fRPCWhitelistArray;
    IBOutlet NSSegmentedControl* fRPCAddRemoveControl;
    NSString* fRPCPassword;
}

- (instancetype)initWithHandle:(tr_session*)handle;

- (void)setAutoUpdateToBeta:(id)sender;

- (void)setPort:(id)sender;
- (void)randomPort:(id)sender;
- (void)setRandomPortOnStart:(id)sender;
- (void)setNat:(id)sender;
- (void)updatePortStatus;
- (void)portCheckerDidFinishProbing:(PortChecker*)portChecker;

@property(nonatomic, readonly) NSArray* sounds;
- (void)setSound:(id)sender;

- (void)setUTP:(id)sender;

- (void)setPeersGlobal:(id)sender;
- (void)setPeersTorrent:(id)sender;

- (void)setPEX:(id)sender;
- (void)setDHT:(id)sender;
- (void)setLPD:(id)sender;

- (void)setEncryptionMode:(id)sender;

- (void)setBlocklistEnabled:(id)sender;
- (void)updateBlocklist:(id)sender;
- (void)setBlocklistAutoUpdate:(id)sender;
- (void)updateBlocklistFields;
- (void)updateBlocklistURLField;
- (void)updateBlocklistButton;

- (void)setAutoStartDownloads:(id)sender;

- (void)setBadge:(id)sender;

- (IBAction)openNotificationSystemPrefs:(NSButton*)sender;

- (void)resetWarnings:(id)sender;

- (void)setDefaultForMagnets:(id)sender;

- (void)setQueue:(id)sender;
- (void)setQueueNumber:(id)sender;

- (void)setStalled:(id)sender;
- (void)setStalledMinutes:(id)sender;

- (void)setDownloadLocation:(id)sender;
- (void)folderSheetShow:(id)sender;
- (void)incompleteFolderSheetShow:(id)sender;
- (void)setUseIncompleteFolder:(id)sender;

- (void)setRenamePartialFiles:(id)sender;

- (IBAction)setShowAddMagnetWindow:(id)sender;
- (void)updateShowAddMagnetWindowField;

- (void)setDoneScriptEnabled:(id)sender;
- (void)doneScriptSheetShow:(id)sender;

- (void)applyRatioSetting:(id)sender;
- (void)setRatioStop:(id)sender;
- (void)updateRatioStopField;
- (void)updateRatioStopFieldOld;

- (void)applyIdleStopSetting:(id)sender;
- (void)setIdleStop:(id)sender;
- (void)updateLimitStopField;

- (void)applySpeedSettings:(id)sender;
- (void)applyAltSpeedSettings;

- (void)updateLimitFields;
- (void)setGlobalLimit:(id)sender;

- (void)setSpeedLimit:(id)sender;
- (void)setAutoSpeedLimit:(id)sender;
- (void)setAutoSpeedLimitTime:(id)sender;
- (void)setAutoSpeedLimitDay:(id)sender;
+ (NSInteger)dateToTimeSum:(NSDate*)date;
+ (NSDate*)timeSumToDate:(NSInteger)sum;

- (void)setAutoImport:(id)sender;
- (void)importFolderSheetShow:(id)sender;

- (void)setAutoSize:(id)sender;

- (void)setRPCEnabled:(id)sender;
- (void)linkWebUI:(id)sender;
- (void)setRPCAuthorize:(id)sender;
- (void)setRPCUsername:(id)sender;
- (void)setRPCPassword:(id)sender;
- (void)updateRPCPassword;
- (void)setRPCPort:(id)sender;
- (void)setRPCUseWhitelist:(id)sender;
- (void)setRPCWebUIDiscovery:(id)sender;
- (void)updateRPCWhitelist;
- (void)addRemoveRPCIP:(id)sender;

- (void)helpForScript:(id)sender;
- (void)helpForPeers:(id)sender;
- (void)helpForNetwork:(id)sender;
- (void)helpForRemote:(id)sender;

- (void)rpcUpdatePrefs;

@end
