# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(bad-input) begin
(bad-input) sorted index -1
(bad-input) end
EOF
pass;
