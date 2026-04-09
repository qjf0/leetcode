#!/usr/bin/env python3
"""
Auto commit message generator for LeetCode repository
Generates commit messages based on git status (new/modified files)
"""

import subprocess
import sys
from datetime import datetime


def run_git_command(cmd):
    """Run git command and return output"""
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    return result.stdout.strip()


def get_staged_files():
    """Get list of staged files"""
    output = run_git_command("git diff --cached --name-status")
    if not output:
        return []

    files = []
    for line in output.split("\n"):
        if line:
            status, filepath = line.split("\t", 1)
            files.append((status, filepath))
    return files


def generate_commit_message(files):
    """Generate commit message based on file changes"""
    if not files:
        return None

    new_files = []
    modified_files = []
    deleted_files = []

    for status, filepath in files:
        if status == "A":
            new_files.append(filepath)
        elif status == "M":
            modified_files.append(filepath)
        elif status == "D":
            deleted_files.append(filepath)
        elif status == "R":
            # Renamed file
            modified_files.append(filepath)

    parts = []

    if new_files:
        if len(new_files) == 1:
            parts.append(f"Add {new_files[0]}")
        else:
            parts.append(f"Add {len(new_files)} files: {', '.join(new_files[:3])}")
            if len(new_files) > 3:
                parts[-1] += f" and {len(new_files) - 3} more"

    if modified_files:
        if len(modified_files) == 1:
            parts.append(f"Update {modified_files[0]}")
        else:
            parts.append(f"Update {len(modified_files)} files")

    if deleted_files:
        if len(deleted_files) == 1:
            parts.append(f"Delete {deleted_files[0]}")
        else:
            parts.append(f"Delete {len(deleted_files)} files")

    # Build final message
    if len(parts) == 1:
        message = parts[0]
    elif len(parts) == 2:
        message = f"{parts[0]}, {parts[1]}"
    else:
        message = f"{parts[0]}, {parts[1]}, {parts[2]}"

    # Add timestamp for uniqueness
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M")
    return f"{message} [{timestamp}]"


def main():
    # Check if there are staged changes
    staged_files = get_staged_files()

    if not staged_files:
        print("No staged files. Please run: git add <files> first")
        print("\nTip: git add .  # to stage all changes")
        sys.exit(1)

    # Generate commit message
    message = generate_commit_message(staged_files)

    if not message:
        print("No changes to commit")
        sys.exit(0)

    # Show generated message
    print(f"Generated commit message:\n  {message}\n")

    # Ask for confirmation
    response = input("Commit with this message? (y/n/e to edit): ").lower()

    if response == "y":
        # Commit with the generated message
        result = subprocess.run(
            ["git", "commit", "-m", message], capture_output=True, text=True
        )
        if result.returncode == 0:
            print("> Commit successful!")
            print(result.stdout)
        else:
            print("> Commit failed:")
            print(result.stderr)

    elif response == "e":
        # Allow user to edit the message
        print(f"\nEdit the message below (save and exit to commit):\n")
        edited = input("New message: ")
        if edited.strip():
            subprocess.run(["git", "commit", "-m", edited.strip()])
            print("> Commit successful!")
        else:
            print("> Empty message, commit cancelled")

    else:
        print("Commit cancelled")


if __name__ == "__main__":
    main()
