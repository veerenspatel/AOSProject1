# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(sl-bad-target) begin
(sl-bad-target) passed in invalid target to symlink
(sl-bad-target) symlink() returned -1
(sl-bad-target) end
sl-bad-target: exit(0)
EOF
pass;
