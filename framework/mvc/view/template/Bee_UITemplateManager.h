//
//	 ______    ______    ______
//	/\  __ \  /\  ___\  /\  ___\
//	\ \  __<  \ \  __\_ \ \  __\_
//	 \ \_____\ \ \_____\ \ \_____\
//	  \/_____/  \/_____/  \/_____/
//
//
//	Copyright (c) 2014-2015, Geek Zoo Studio
//	http://www.bee-framework.com
//
//
//	Permission is hereby granted, free of charge, to any person obtaining a
//	copy of this software and associated documentation files (the "Software"),
//	to deal in the Software without restriction, including without limitation
//	the rights to use, copy, modify, merge, publish, distribute, sublicense,
//	and/or sell copies of the Software, and to permit persons to whom the
//	Software is furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//	IN THE SOFTWARE.
//

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import "Bee_Precompile.h"
#import "Bee_Package.h"
#import "Bee_Foundation.h"
#import "Bee_ViewPackage.h"

#import "Bee_UILayout.h"
#import "Bee_UIStyle.h"
#import "Bee_UITemplate.h"

#pragma mark -

AS_PACKAGE( BeePackage_UI, BeeUITemplateManager, templateManager );

#pragma mark -

@interface BeeUITemplateManager : NSObject

AS_NOTIFICATION( SYNC_BEGIN )
AS_NOTIFICATION( SYNC_PROGRESS )
AS_NOTIFICATION( SYNC_FINISHED )
AS_NOTIFICATION( SYNC_FAILED )
AS_NOTIFICATION( SYNC_CANCELLED )

AS_NOTIFICATION( PACKAGE_WILL_CHANGE )
AS_NOTIFICATION( PACKAGE_DID_CHANGED )

AS_SINGLETON( BeeUITemplateManager )

@property (nonatomic, retain) NSString *		defaultPassword;
@property (nonatomic, retain) NSString *		defaultResourcePath;
@property (nonatomic, retain) NSString *		defaultTemplatePath;
@property (nonatomic, retain) NSString *		defaultPackage;
@property (nonatomic, retain) NSString *		currentPackage;

@property (nonatomic, retain) NSArray *			packages;
@property (nonatomic, retain) NSDictionary *	templates;
@property (nonatomic, readonly) NSArray *		all;	// syntax sugar

@property (nonatomic, readonly) BOOL			syncing;
@property (nonatomic, readonly) CGFloat			syncProgress;

- (BeeUITemplate *)fromName:(NSString *)resName;
- (BeeUITemplate *)fromFile:(NSString *)resName;
- (BeeUITemplate *)fromCache:(NSString *)resName;
- (BeeUITemplate *)fromPackage:(NSString *)resName;
- (BeeUITemplate *)fromResource:(NSString *)resName;

- (void)preloadResources;
- (void)preloadPackages;
- (void)clearCache;

- (void)sync:(NSString *)url;
- (void)sync:(NSString *)url password:(NSString *)password;
- (void)stop;

- (BOOL)applyPackage:(NSString *)package;

- (id)objectForKeyedSubscript:(id)key;
- (void)setObject:(id)obj forKeyedSubscript:(id)key;

@end

#endif	// #if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
