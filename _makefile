# .SILENT:

all: generate

# List of all directories containing a makefile
source_dirs := $(dir $(wildcard */makefile))

# Build each project
foo:
	$(foreach dir, $(source_dirs), make -j -C $(dir);)

# Clean each project
clean:
	$(foreach dir, $(source_dirs), make -j -C $(dir) clean;)

generate: foo
	echo '## Big O Notation' > readme.md
	echo 'See [how this documentation is generated](install.md).' >> readme.md
	$(foreach dir, $(source_dirs), make -j -C $(dir) generate;)
