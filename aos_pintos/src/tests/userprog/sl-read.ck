# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(sl-read) begin
(sl-read) create "test.txt"
(sl-read) open "test.txt"
(sl-read) symlink() successfully returned 0
(sl-read) open "test-link.txt"
(sl-read) write content to "test.txt"
(sl-read) read "test-link.txt"
(sl-read) test-link.txt reads: 'This is a test'
(sl-read) end
sl-read: exit(0)
EOF
pass;
