# Included from top-level .conf file

filters = "chartable,dkim,spf,regexp,fuzzy_check";
raw_mode = false;
one_shot = false;
cache_file = "$DBDIR/symbols.cache";
# How often maps are checked (
map_watch_interval = 5min;
# Multiplier for watch interval for files
map_file_watch_multiplier = 0.1;
dynamic_conf = "$DBDIR/rspamd_dynamic";
history_file = "$DBDIR/rspamd.history";
check_all_filters = false;
dns {
    timeout = 1s;
    sockets = 16;
    retransmits = 5;
}
tempdir = "/tmp";
url_tld = "${SHAREDIR}/effective_tld_names.dat";
classify_headers = [
	"User-Agent",
	"X-Mailer",
	"Content-Type",
	"X-MimeOLE",
];

control_socket = "$DBDIR/rspamd.sock mode=0600";
history_rows = 200;
explicit_modules = ["settings", "bayes_expiry"];

# Scan messages even if they are not MIME
allow_raw_input = true;

# Start ignore words when reaching the following limit, so the total
# amount of words processed will not be *LIKELY more than the twice of that limit
words_decay = 600;

# Write statistics about rspamd usage to the round-robin database
rrd = "${DBDIR}/rspamd.rrd";

# Local networks
local_addrs = [192.168.0.0/16, 10.0.0.0/8, 172.16.0.0/12, fd00::/8, 169.254.0.0/16, fe80::/10];
hs_cache_dir = "${DBDIR}/";

# Timeout for messages processing (must be larger than any internal timeout used)
task_timeout = 8s;

# Emit soft reject when timeout takes place
soft_reject_on_timeout = false;
