# Text Editor

A simple text editor for opening and editing files.

## Features

- Open existing files
- Edit text content
- Save changes to files

## Keyboard Shortcuts

- **Ctrl+S** - Save the current file
- **Ctrl+Q** - Quit the editor
  - If the file has been modified, press **Ctrl+Q** again to confirm quit without saving
- **$** - Go to end of line
- **0** - Go to beginning of the line

## Known Limitations

### Character Encoding

**UTF-8 is supported.** Best results are with ASCII-only characters.

## Usage

1. Launch the text editor
2. Open a file to begin editing
3. Make your changes
4. Press **Ctrl+S** to save
5. Press **Ctrl+Q** to quit (press again if file has unsaved changes)

## Notes

- Unsaved changes will trigger a confirmation prompt when attempting to quit
- The editor works best with plain text files using standard ASCII encoding, but UTF-8 is supported.
