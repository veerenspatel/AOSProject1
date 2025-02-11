# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(not-found) begin
(not-found) sorted index -1
(not-found) end
EOF
pass;
