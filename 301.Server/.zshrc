if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# Macos Iterm2
test -e "${HOME}/.iterm2_shell_integration.zsh" && source "${HOME}/.iterm2_shell_integration.zsh"

# Remove older command from the history if a duplicate is to be added.
setopt HIST_IGNORE_ALL_DUPS

# ------------------
# Initialize modules
# ------------------

ZIM_HOME=${ZDOTDIR:-${HOME}}/.zim
# Download zimfw plugin manager if missing.
if [[ ! -e ${ZIM_HOME}/zimfw.zsh ]]; then
  if (( ${+commands[curl]} )); then
    curl -fsSL --create-dirs -o ${ZIM_HOME}/zimfw.zsh \
        https://github.com/zimfw/zimfw/releases/latest/download/zimfw.zsh
  else
    mkdir -p ${ZIM_HOME} && wget -nv -O ${ZIM_HOME}/zimfw.zsh \
        https://github.com/zimfw/zimfw/releases/latest/download/zimfw.zsh
  fi
fi
# Install missing modules, and update ${ZIM_HOME}/init.zsh if missing or outdated.
if [[ ! ${ZIM_HOME}/init.zsh -nt ${ZDOTDIR:-${HOME}}/.zimrc ]]; then
  source ${ZIM_HOME}/zimfw.zsh init -q
fi
# Initialize modules.
source ${ZIM_HOME}/init.zsh

zvm_after_init_commands+=('[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh')

# ------------------------------
# Custom function
# ------------------------------

# ranger
function ranger {
    local IFS=$'\t\n'
    local tempfile="$(mktemp -t tmp.XXXXXX)"
    local ranger_cmd=(
        command
        ranger
        --cmd="map q chain shell echo %d > "$tempfile"; quitall"
    )
    
    ${ranger_cmd[@]} "$@"
    if [[ -f "$tempfile" ]] && [[ "$(cat -- "$tempfile")" != "$(echo -n `pwd`)" ]]; then
        # echo "zoxide -- "$(cat "$tempfile")" || return"
        cd -- "$(cat "$tempfile")"; zoxide add "$(cat "$tempfile")" || return
    fi
    command rm -f -- "$tempfile" 2>/dev/null
}

# Usage mcd <directory>
function mcd() {
    mkdir -p "$1"
    cd "$1"
}

function c() {
    extension="${1##*.}"
    filename="${1%.*}"
    if [[ "$extension" == "cpp" ]]; then
        clang++ $1 -o $filename && ./$filename && rm $filename
    elif [[ "$extension" == "c" ]]; then
        clang $1 -o $filename && ./$filename && rm $filename
    fi
}

# extract domain and geoip 
function dnsq () {
    url="$(echo "$1" | rg "^(https?://)?([a-z0-9.-]+)" -or '$2')"
    echo $url
    curl --http2 -H 'accept: application/dns-json' https://1.1.1.1/dns-query\?name\=$url | jq '.Answer | .[] | .data' | nali
}

# Usage: gcp "Commit message"
function gcp() {
    git commit -a -m "$1"
    git push
}

# ------------------------------
# alias
# ------------------------------

# fzf
zvm_after_init_commands+=('[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh')

# alias for m1
alias xxx="arch -x86_64"

# alias for git
alias gl="git log --all --decorate --oneline --graph"
alias gs='git status'
alias gc='git commit'
alias gca='git commit -a'
alias ga='git add'
alias gc1='git clone --depth=1'
alias lg='lazygit'

# alias for yadm
alias ydf="yadm diff"
alias ys='yadm status'
alias yca='yadm commit -a'
alias yp='yadm push'

# alias for ranger
alias ra='ranger'

# alias for cli
alias mv='mv -i'
alias cp='cp -i'
alias mkdir='mkdir -p'

# alias for nodejs
alias pnpm="npm"

# alias for vim
alias vim=nvim
alias lv=lvim

# alias for modern linux command
alias bat="bat --theme OneHalfLight "
alias zz="zi"

# alias for homebrew
alias bse='brew search'
alias bup="brew update && brew upgrade && brew cleanup"
alias bin="brew install"
alias brm="brew remove"
alias bif="brew info"
alias bout="brew outdated"

# alias for python
alias py="python"
alias py3="python3"
alias act="source bin/activate"
alias deact="deactivate"

# pnpm
export PNPM_HOME="/Users/ccyynn/Library/pnpm"
export PATH="$PNPM_HOME:$PATH"
# pnpm end
