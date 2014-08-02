// Copyright (c) 2014 Stanislas Polu.
// Copyright (c) 2012 The Chromium Authors.
// See the LICENSE file.

#include "src/browser/dialog/javascript_dialog_manager.h"

#include "base/command_line.h"
#include "base/logging.h"
#include "base/strings/utf_string_conversions.h"
#include "net/base/net_util.h"
#include "content/public/browser/web_contents.h"
#include "content/public/browser/web_contents_view.h"

#include "src/common/switches.h"

using namespace content;

namespace exo_shell {

ExoShellJavaScriptDialogManager::ExoShellJavaScriptDialogManager() 
{
}

ExoShellJavaScriptDialogManager::~ExoShellJavaScriptDialogManager() 
{
}

void 
ExoShellJavaScriptDialogManager::RunJavaScriptDialog(
    WebContents* web_contents,
    const GURL& origin_url,
    const std::string& accept_lang,
    JavaScriptMessageType javascript_message_type,
    const base::string16& message_text,
    const base::string16& default_prompt_text,
    const DialogClosedCallback& callback,
    bool* did_suppress_message) 
{
  if (!dialog_request_callback_.is_null()) {
    dialog_request_callback_.Run();
    callback.Run(true, base::string16());
    dialog_request_callback_.Reset();
    return;
  }

  /* TODO(spolu): Expose to API */
  *did_suppress_message = true;
  return;
}

void 
ExoShellJavaScriptDialogManager::RunBeforeUnloadDialog(
    WebContents* web_contents,
    const base::string16& message_text,
    bool is_reload,
    const DialogClosedCallback& callback) 
{
  if (!dialog_request_callback_.is_null()) {
    dialog_request_callback_.Run();
    callback.Run(true, base::string16());
    dialog_request_callback_.Reset();
    return;
  }

  /* TODO(spolu): Expose to API */
  callback.Run(true, base::string16());
  return;
}


void 
ExoShellJavaScriptDialogManager::CancelActiveAndPendingDialogs(
    WebContents* web_contents) 
{
  /* TODO(spolu): Expose to API */
}

void 
ExoShellJavaScriptDialogManager::WebContentsDestroyed(
    WebContents* web_contents) 
{
}

void 
ExoShellJavaScriptDialogManager::DialogClosed(
    JavaScriptDialog* dialog) 
{
  /* TODO(spolu): Expose to API */
}

} // namespace exo_shell