# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(sl-check) begin
(sl-check) create "test.txt"
(sl-check) open "test.txt"
(sl-check) symlink() successfully returned 0
(sl-check) open "test-link.txt"
(sl-check) end
sl-check: exit(0)
EOF
pass;
