{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2020 Collabora Ltd.  }
  {                         @author George Kiagiadakis <george.kiagiadakis@collabora.com>  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_SESSION_MANAGER_INTROSPECT_FUNCS_H}
{$define PIPEWIRE_EXT_SESSION_MANAGER_INTROSPECT_FUNCS_H}  



{ C++ extern C conditionnal removed }
  {*
   * \addtogroup pw_session_manager
   * \
    }
(* error 
static inline struct pw_session_info *
(* error 
			const struct pw_session_info *update)
 in declarator_list *)
 in declarator_list *)
(* error 
	struct extended_info {
 in declarator_list *)
(* error 
		struct pw_properties *props_storage;
 in declarator_list *)
(* error 
		struct pw_session_info info;
in declaration at line 28 *)
(* error 
	} *ext;
in declaration at line 29 *)
(* error 
	if (update == NULL)
 in declarator_list *)
(* error 
	if (info == NULL) {
 in declarator_list *)
(* error 
		ext = (struct extended_info *) calloc(1, sizeof(*ext));
 in declarator_list *)
(* error 
		if (ext == NULL)
 in declarator_list *)
(* error 
		info = &ext->info;
in declaration at line 39 *)
(* error 
		info->id = update->id;
(* error 
		info->id = update->id;
 in declarator_list *)
(* error 
	} else {
in declaration at line 42 *)
(* error 
	}
in declaration at line 45 *)
(* error 
	if (update->change_mask & PW_SESSION_CHANGE_MASK_PROPS) {
 in declarator_list *)
(* error 
		if (!ext->props_storage) {
 in declarator_list *)
(* error 
			ext->props_storage = pw_properties_new(NULL, NULL);
(* error 
			ext->props_storage = pw_properties_new(NULL, NULL);
 in declarator_list *)
 in declarator_list *)
(* error 
			info->props = &ext->props_storage->dict;
(* error 
			info->props = &ext->props_storage->dict;
 in declarator_list *)
(* error 
		}
in declaration at line 52 *)
(* error 
		pw_properties_update(ext->props_storage, update->props);
(* error 
		pw_properties_update(ext->props_storage, update->props);
 in declarator_list *)
 in declarator_list *)
(* error 
	}
in declaration at line 56 *)
(* error 
		free((void *) info->params);
 in declarator_list *)
(* error 
		if (update->params) {
 in declarator_list *)
(* error 
			size_t size = info->n_params * sizeof(struct spa_param_info);
 in declarator_list *)
(* error 
			info->params = (struct spa_param_info *) malloc(size);
(* error 
			info->params = (struct spa_param_info *) malloc(size);
 in declarator_list *)
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
		}
in declaration at line 64 *)
(* error 
	}
in declaration at line 66 *)
(* error 
}
in declaration at line 73 *)
(* error 
		struct pw_session_info info;
in declaration at line 74 *)
(* error 
	} *ext = SPA_CONTAINER_OF(info, struct extended_info, info);
in declaration at line 75 *)
(* error 
	pw_properties_free(ext->props_storage);
 in declarator_list *)
(* error 
	free((void *) info->params);
 in declarator_list *)

      var
        ext : free;cvar;public;
(* error 
}
in declaration at line 87 *)
(* error 
		struct pw_endpoint_info info;
in declaration at line 88 *)
(* error 
	} *ext;
in declaration at line 89 *)
(* error 
	if (update == NULL)
 in declarator_list *)
(* error 
	if (info == NULL) {
 in declarator_list *)
(* error 
		ext = (struct extended_info *) calloc(1, sizeof(*ext));
 in declarator_list *)
(* error 
		if (ext == NULL)
 in declarator_list *)
(* error 
		info = &ext->info;
in declaration at line 99 *)
(* error 
		info->id = update->id;
(* error 
		info->id = update->id;
 in declarator_list *)
(* error 
		info->name = strdup(update->name);
(* error 
		info->name = strdup(update->name);
 in declarator_list *)
(* error 
		info->media_class = strdup(update->media_class);
(* error 
		info->media_class = strdup(update->media_class);
 in declarator_list *)
(* error 
		info->direction = update->direction;
(* error 
		info->direction = update->direction;
 in declarator_list *)
(* error 
		info->flags = update->flags;
(* error 
		info->flags = update->flags;
 in declarator_list *)
(* error 
	} else {
in declaration at line 106 *)
(* error 
	}
in declaration at line 109 *)
(* error 
	if (update->change_mask & PW_ENDPOINT_CHANGE_MASK_STREAMS)
 in declarator_list *)
(* error 
	if (update->change_mask & PW_ENDPOINT_CHANGE_MASK_SESSION)
 in declarator_list *)
(* error 
	if (update->change_mask & PW_ENDPOINT_CHANGE_MASK_PROPS) {
 in declarator_list *)
(* error 
		if (!ext->props_storage) {
 in declarator_list *)
(* error 
			ext->props_storage = pw_properties_new(NULL, NULL);
(* error 
			ext->props_storage = pw_properties_new(NULL, NULL);
 in declarator_list *)
 in declarator_list *)
(* error 
			info->props = &ext->props_storage->dict;
(* error 
			info->props = &ext->props_storage->dict;
 in declarator_list *)
(* error 
		}
in declaration at line 122 *)
(* error 
		pw_properties_update(ext->props_storage, update->props);
(* error 
		pw_properties_update(ext->props_storage, update->props);
 in declarator_list *)
 in declarator_list *)
(* error 
	}
in declaration at line 126 *)
(* error 
		free((void *) info->params);
 in declarator_list *)
(* error 
		if (update->params) {
 in declarator_list *)
(* error 
			size_t size = info->n_params * sizeof(struct spa_param_info);
 in declarator_list *)
(* error 
			info->params = (struct spa_param_info *) malloc(size);
(* error 
			info->params = (struct spa_param_info *) malloc(size);
 in declarator_list *)
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
		}
in declaration at line 134 *)
(* error 
	}
in declaration at line 136 *)
(* error 
}
in declaration at line 143 *)
(* error 
		struct pw_endpoint_info info;
in declaration at line 144 *)
(* error 
	} *ext = SPA_CONTAINER_OF(info, struct extended_info, info);
in declaration at line 145 *)
(* error 
	pw_properties_free(ext->props_storage);
 in declarator_list *)
(* error 
	free(info->name);
 in declarator_list *)
(* error 
	free(info->media_class);
 in declarator_list *)
(* error 
	free((void *) info->params);
 in declarator_list *)
        ext : free;cvar;public;
(* error 
}
in declaration at line 159 *)
(* error 
		struct pw_endpoint_stream_info info;
in declaration at line 160 *)
(* error 
	} *ext;
in declaration at line 161 *)
(* error 
	if (update == NULL)
 in declarator_list *)
(* error 
	if (info == NULL) {
 in declarator_list *)
(* error 
		ext = (struct extended_info *) calloc(1, sizeof(*ext));
 in declarator_list *)
(* error 
		if (ext == NULL)
 in declarator_list *)
(* error 
		info = &ext->info;
in declaration at line 171 *)
(* error 
		info->id = update->id;
(* error 
		info->id = update->id;
 in declarator_list *)
(* error 
		info->endpoint_id = update->endpoint_id;
(* error 
		info->endpoint_id = update->endpoint_id;
 in declarator_list *)
(* error 
		info->name = strdup(update->name);
(* error 
		info->name = strdup(update->name);
 in declarator_list *)
(* error 
	} else {
in declaration at line 176 *)
(* error 
	}
in declaration at line 179 *)
(* error 
	if (update->change_mask & PW_ENDPOINT_STREAM_CHANGE_MASK_LINK_PARAMS) {
 in declarator_list *)
(* error 
		free(info->link_params);
 in declarator_list *)
(* error 
		info->link_params = update->link_params ?
(* error 
		info->link_params = update->link_params ?
 in declarator_list *)
(* error 
	}
in declaration at line 188 *)
(* error 
			info->props = &ext->props_storage->dict;
(* error 
			info->props = &ext->props_storage->dict;
 in declarator_list *)
(* error 
		}
in declaration at line 191 *)
(* error 
		pw_properties_update(ext->props_storage, update->props);
(* error 
		pw_properties_update(ext->props_storage, update->props);
 in declarator_list *)
 in declarator_list *)
(* error 
	}
in declaration at line 195 *)
(* error 
		free((void *) info->params);
 in declarator_list *)
(* error 
		if (update->params) {
 in declarator_list *)
(* error 
			size_t size = info->n_params * sizeof(struct spa_param_info);
 in declarator_list *)
(* error 
			info->params = (struct spa_param_info *) malloc(size);
(* error 
			info->params = (struct spa_param_info *) malloc(size);
 in declarator_list *)
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
		}
in declaration at line 203 *)
(* error 
	}
in declaration at line 205 *)
(* error 
}
in declaration at line 212 *)
(* error 
		struct pw_endpoint_stream_info info;
in declaration at line 213 *)
(* error 
	} *ext = SPA_CONTAINER_OF(info, struct extended_info, info);
in declaration at line 214 *)
(* error 
	pw_properties_free(ext->props_storage);
 in declarator_list *)
(* error 
	free(info->name);
 in declarator_list *)
(* error 
	free(info->link_params);
 in declarator_list *)
(* error 
	free((void *) info->params);
 in declarator_list *)
        ext : free;cvar;public;
(* error 
}
in declaration at line 229 *)
(* error 
		struct pw_endpoint_link_info info;
in declaration at line 230 *)
(* error 
	} *ext;
in declaration at line 231 *)
(* error 
	if (update == NULL)
 in declarator_list *)
(* error 
	if (info == NULL) {
 in declarator_list *)
(* error 
		ext = (struct extended_info *) calloc(1, sizeof(*ext));
 in declarator_list *)
(* error 
		if (ext == NULL)
 in declarator_list *)
(* error 
		info = &ext->info;
in declaration at line 241 *)
(* error 
		info->id = update->id;
(* error 
		info->id = update->id;
 in declarator_list *)
(* error 
		info->session_id = update->session_id;
(* error 
		info->session_id = update->session_id;
 in declarator_list *)
(* error 
		info->output_endpoint_id = update->output_endpoint_id;
(* error 
		info->output_endpoint_id = update->output_endpoint_id;
 in declarator_list *)
(* error 
		info->output_stream_id = update->output_stream_id;
(* error 
		info->output_stream_id = update->output_stream_id;
 in declarator_list *)
(* error 
		info->input_endpoint_id = update->input_endpoint_id;
(* error 
		info->input_endpoint_id = update->input_endpoint_id;
 in declarator_list *)
(* error 
		info->input_stream_id = update->input_stream_id;
(* error 
		info->input_stream_id = update->input_stream_id;
 in declarator_list *)
(* error 
	} else {
in declaration at line 249 *)
(* error 
	}
in declaration at line 252 *)
(* error 
	if (update->change_mask & PW_ENDPOINT_LINK_CHANGE_MASK_STATE) {
 in declarator_list *)
(* error 
		info->state = update->state;
 in declarator_list *)
(* error 
		free(info->error);
 in declarator_list *)
(* error 
		info->error = update->error ? strdup(update->error) : NULL;
(* error 
		info->error = update->error ? strdup(update->error) : NULL;
 in declarator_list *)
(* error 
	}
in declaration at line 261 *)
(* error 
			info->props = &ext->props_storage->dict;
(* error 
			info->props = &ext->props_storage->dict;
 in declarator_list *)
(* error 
		}
in declaration at line 264 *)
(* error 
		pw_properties_update(ext->props_storage, update->props);
(* error 
		pw_properties_update(ext->props_storage, update->props);
 in declarator_list *)
 in declarator_list *)
(* error 
	}
in declaration at line 268 *)
(* error 
		free((void *) info->params);
 in declarator_list *)
(* error 
		if (update->params) {
 in declarator_list *)
(* error 
			size_t size = info->n_params * sizeof(struct spa_param_info);
 in declarator_list *)
(* error 
			info->params = (struct spa_param_info *) malloc(size);
(* error 
			info->params = (struct spa_param_info *) malloc(size);
 in declarator_list *)
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
(* error 
			memcpy(info->params, update->params, size);
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
		}
in declaration at line 276 *)
(* error 
	}
in declaration at line 278 *)
(* error 
}
in declaration at line 285 *)
(* error 
		struct pw_endpoint_link_info info;
in declaration at line 286 *)
(* error 
	} *ext = SPA_CONTAINER_OF(info, struct extended_info, info);
in declaration at line 287 *)
(* error 
	pw_properties_free(ext->props_storage);
 in declarator_list *)
(* error 
	free(info->error);
 in declarator_list *)
(* error 
	free((void *) info->params);
 in declarator_list *)
        ext : free;cvar;public;
(* error 
}
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_SESSION_MANAGER_INTROSPECT_FUNCS_H  }

