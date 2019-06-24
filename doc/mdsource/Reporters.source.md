<a id="top"></a>

# Reporter



<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Contents**

- [Supported Diff Tools](#supported-diff-tools)
  - [Mac](#mac)
  - [Linux](#linux)
  - [Windows](#windows)
- [Registering a default reporter](#registering-a-default-reporter)
- [Miscellaneous Helper Reporters](#miscellaneous-helper-reporters)
  - [Auto-approving](#auto-approving)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Supported Diff Tools

The DiffReporter class goes through a chain of possible reporters to find the first option installed on your system.
Currently the search goes in this order:

### Mac

snippet: mac_diff_reporters

### Linux

snippet: linux_diff_reporters

### Windows

snippet: windows_diff_reporters

## Registering a default reporter

At present, the default Reporter is the DiffReporter. Whenever you call Approvals, you have the chance to pass in your own Reporter. However, if you would like to change what the default reporter is when you don't pass in a specific Reporter, you can do this at a global or per-test level, by adding the line:

snippet: use_as_default_reporter_in_main

The return value will restore the original reporter when the object destructs. Because of this, if you do not store the result in a variable, it will immediately undo itself by the end of the line.

## Miscellaneous Helper Reporters

While most reporters open some sort of external program, for the purpose of understanding how the tests went wrong, and verifying the correct answer, there are some reporters that are helpful for specific situations.

### Auto-approving

There are three reporters that can help with the approving of single or multiple tests.

* `AutoApproveIfMissingReporter`: if there is no approved file already, the received file will automatically be copied over the approved one. Otherwise, it does nothing. One possible cause for confusion here is if you ran the test previously with a standard reporter, that will have created an almost-empty approved file, which will then block this from working.
* `ClipboardReporter`: this puts the command-line to moved the approve file on to your computer's clipboard. You then review this, and paste it in to a terminal window. This only works with one test at a time.
* `AutoApproveReporter`: be careful, this will overwrite every existing ".approved" file, with no confirmation. This is best used when you are expecting large numbers of files that are already version-controlled to be updated, and you would rather review the changes in your control system. 

---

[Back to User Guide](/doc/README.md#top)