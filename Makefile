# find ./spa -type f -name "*.h" | xargs -I {} -n 1 h2pas -D -C -l spa-0.2 -o out/"$(basename {}).pas" {}
PIPEWIRE = /usr/include/pipewire-0.3/pipewire
OUTDIR = inc/
H2PAS_FLAGS = -d -C -p

H_FILES = $(shell find $(PIPEWIRE) -type f -name '*.h')
PAS_FILES = $(patsubst $(PIPEWIRE)%.h, $(OUTDIR)%.inc, $(H_FILES))

all: bindings

.PHONY: clean
clean:
	rm -rf $(OUTDIR)

.PHONY: bindings
bindings: $(PAS_FILES)

$(OUTDIR)%.inc: $(PIPEWIRE)%.h
	mkdir -p "$(@D)"
	h2pas -i -l $(shell pkg-config --libs libpipewire-0.3 | cut -c 3-) $(H2PAS_FLAGS) -o "$@" "$<"
	sed -i 's/{\$$include .*}//g' "$@"
