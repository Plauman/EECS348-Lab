# AI Usage Log

## Interaction 1
### User
what to do

### Assistant Summary
Reviewed the uploaded Lab 3 materials and explained the overall workflow: configure the KU People environment, create four web-programming practices, test them, and publish the work to the People server and GitHub.

## Interaction 2
### User
it says 403 forbidden

### Assistant Summary
Explained that a 403 error was likely related to web-directory permissions or setup and provided commands to check the `public_html` directory, run the permission script, and verify file permissions.

## Interaction 3
### User
<<ImageDisplayed>>

### Assistant Summary
Reviewed the terminal screenshot and identified that the permission script had been requested from the user's own People directory rather than the instructor's directory. Provided the corrected `wget` command and next steps.

## Interaction 4
### User
<<ImageDisplayed>>

### Assistant Summary
Reviewed the new terminal screenshot, confirmed that `grant_permission.sh` downloaded and ran successfully, and instructed the user to test their KU People URL.

## Interaction 5
### User
I see everything

### Assistant Summary
Confirmed that the environment setup was complete and instructed the user to create `practice1.html` with Nano.

## Interaction 6
### User
It’s open

### Assistant Summary
Provided complete HTML/CSS code for Practice 1 containing profile text, a KU image, a hyperlink, and an embedded YouTube video, along with instructions for saving and publishing the file.

## Interaction 7
### User
how do i change the video

### Assistant Summary
Explained how YouTube embed URLs work and how to replace the video ID in the iframe with the ID from another YouTube video.

## Interaction 8
### User
https://www.youtube.com/watch?v=dvgZkm1xWPE this video

### Assistant Summary
Extracted the YouTube video ID `dvgZkm1xWPE` and provided the updated iframe code for that video.

## Interaction 9
### User
give me the entire code with that viedo

### Assistant Summary
Provided the full updated Practice 1 HTML document with the requested YouTube video embedded and repeated the save and permission-script steps.

## Interaction 10
### User
looks good

### Assistant Summary
Confirmed Practice 1 was complete, summarized the requirements for Practice 2, and instructed the user to create `practice2.html`.

## Interaction 11
### User
its open

### Assistant Summary
Provided complete Practice 2 HTML and JavaScript code that accepts RGB values for text and border colors and a border-width value, then dynamically applies those styles to a paragraph.

## Interaction 12
### User
that works 

### Assistant Summary
Confirmed Practice 2 was complete, summarized the password-verification requirements for Practice 3, and instructed the user to create `practice3.html`.

## Interaction 13
### User
in

### Assistant Summary
Provided complete Practice 3 HTML and JavaScript code that reads two password entries, checks for a minimum length of eight characters, checks whether they match, and displays the appropriate alert.

## Interaction 14
### User
works well

### Assistant Summary
Confirmed Practice 3 was complete and instructed the user to create `practice4.html` for the PHP multiplication-table exercise.

## Interaction 15
### User
in

### Assistant Summary
Provided complete Practice 4 HTML/PHP code that accepts a number and generates a multiplication table with row and column indexes. Also explained the potential `.html` versus `.php` extension issue.

## Interaction 16
### User
works

### Assistant Summary
Confirmed that all four practices were working and explained that the remaining Lab 3 requirement was publishing the files to GitHub.

## Interaction 17
### User
the image on the first one just says ku jayhawk

### Assistant Summary
Explained that the image had failed to load and the browser was displaying the image's alternate text. Suggested using a locally stored image in `public_html` and updating the image `src`.

## Interaction 18
### User
its a png i just downloaded to my folder

### Assistant Summary
Explained how to copy a downloaded PNG into `public_html`, reference the local PNG from `practice1.html`, rerun the permission script, and refresh the page.

## Interaction 19
### User
KUMarks_Jayhawk.png

### Assistant Summary
Provided exact commands using the filename `KUMarks_Jayhawk.png` to copy the image from Downloads into `public_html`, update Practice 1, and rerun the permission script.

## Interaction 20
### User
works

### Assistant Summary
Confirmed that the Practice 1 image and all four exercises were working, then returned to the remaining GitHub publishing requirement.

## Interaction 21
### User
how can i have a website url in a folder on github

### Assistant Summary
Explained how Lab 3 could be stored inside a folder of an existing GitHub repository and how the folder would have its own GitHub URL. Distinguished a GitHub source-folder URL from a live website hosted through GitHub Pages and noted that the KU People URL already serves as the live site.

## Interaction 22
### User
follow these instructions

### Assistant Summary
Reviewed the uploaded Gen-AI Log Guide and explained its required workflow: finish the lab, provide the instructor's AI usage log instructions in the same conversation, generate Markdown beginning with `# AI Usage Log`, and submit the resulting `ai_usage_log.md`.

## Interaction 23
### User
generate the file

### Assistant Summary
Generated the requested `ai_usage_log.md` file documenting the Lab 3 AI interactions from this conversation.
